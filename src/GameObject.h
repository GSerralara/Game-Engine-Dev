#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include "framework.h"
class GameObject
{
public:
	//some atributes
	std::string name;
	Matrix44 model;

	GameObject* parent;
	std::vector<GameObject*> children;

	//empty functions
	GameObject();
	//~GameObject();
	virtual void render();
	virtual void update(float elapsed_time);
	void addChild(GameObject* obj);
	void removeChild(GameObject* obj);
	void clear();
	void GameObject::checkColisions();
	GameObject* lookInChilds(std::string);
	std::vector<GameObject*> GameObject::returnAllCollidableChilds();
	Matrix44 getGlobalMatrix(); //returns transform in world coordinates
};
#endif // DEBUG