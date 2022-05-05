#pragma once
#ifndef GAMEOBJECTENVIRONMENT_H
#define GAMEOBJECTENVIRONMENT_H
#include "GameObject.h"
#include "ResourceManager.h"
#include <string.h>
#include "mesh.h"
#include "texture.h"

class GameObjectEnvironment : public GameObject
{
public:
	//Attributes of this class
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector3 color;

	GameObjectEnvironment();
	GameObjectEnvironment(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);
	
	//~GameObjectEnvironment();
	//overwritten virtual functions
	void render();
	void update(float dt);

};
#endif // !GAMEOBJECTENVIRONMENT_H