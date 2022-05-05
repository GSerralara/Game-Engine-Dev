#include "GameObject.h"
#include <algorithm>
#include "GameObjectEnvironment.h"
#include "gameobjectmesh.h"
GameObject::GameObject() {
	parent = NULL;
}
void GameObject::render() {
	for (int i = 0; i < this->children.size(); i++) {
		this->children[i]->render();
	}
}
void GameObject::update(float elapsed_time) {
	for (int i = 0; i < this->children.size(); i++) {
		this->children[i]->update(elapsed_time);
	}
}
void GameObject::addChild(GameObject* obj) {
	//make this object the parent of the child
	obj->parent = this;
	//add to list
	this->children.push_back(obj);
}
void GameObject::removeChild(GameObject* obj) {
	//moves obj to end of vector
	std::vector<GameObject*>::iterator i = std::remove(this->children.begin(),
		this->children.end(), obj);
	//actually removes it
	this->children.erase(i, this->children.end());
	//deletes the memory associated with obj
	delete (obj);
}
void GameObject::clear() {
	for (int i = 0; i < this->children.size(); i++) {
		delete this->children[i];
	}
	this->children.clear();
}
void GameObject::checkColisions() {

}
GameObject* GameObject::lookInChilds(std::string nomObj) {
	bool found = false;
	GameObject* toReturn = NULL;
	for (int i = 0; i < this->children.size(); i++) {
		if (this->children[i]->name == nomObj) {
			//std::cout << "Trobat objecte amb nom: " << this->children[i]->name << std::endl;
			toReturn = children[i];
			found = true;
		}
	}
	if (found)
		return toReturn;
	//if we get here we haven't found object
	//so we look in children

	for (int i = 0; i < this->children.size(); i++) {
		toReturn = children[i]->lookInChilds(nomObj);
	}
	std::cout << "Objecte no trobat" << std::endl;
	return toReturn;
}
std::vector<GameObject*> GameObject::returnAllCollidableChilds() {
	std::vector<GameObject*> returnObject;

	for (int i = 0; i < this->children.size(); i++) {

		if (this->children[i]->children.size() == 0) {
			if (((GameObjectMesh*)this->children[i])->isCollide == 1) {
				//std::cout << this->children[i]->name << std::endl;
				//std::cout << (((GameObjectMesh*)this->children[i])->isCollide) << std::endl;

				returnObject.push_back(this->children[i]);
			}

		}
		else {
			std::vector<GameObject*> returnObjectTmp = this->children[i]->returnAllCollidableChilds();
			returnObject.insert(returnObject.end(), returnObjectTmp.begin(), returnObjectTmp.end());
		}
	}
	return returnObject;
}
Matrix44 GameObject::getGlobalMatrix() {
	if (this->parent)
		return this->parent->getGlobalMatrix() * this->model;
	else
		return this->model;
}