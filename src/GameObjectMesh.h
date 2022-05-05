#pragma once
#ifndef GAMEOBJECTMESH_H
#define GAMEOBJECTMESH_H
#include "GameObject.h"
#include "ResourceManager.h"
#include "camera.h"
#include "mesh.h"
#include "texture.h"
#include <string>
#include "coldet/coldet.h"
class GameObjectMesh : public GameObject {
public:
	//Attributes of this class
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
	Vector3 color;
	bool isCollide;

	GameObjectMesh();
	GameObjectMesh(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);
	//~GameObjectMesh();
	//overwritten virtual functions

	void render();
	void update(float dt);
};
#endif