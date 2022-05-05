#pragma once
#include "GameObjectMesh.h"
#include "mesh.h"
#include "texture.h"
#include <string>


class GameObjectPlayer : public GameObjectMesh {
public:
	GameObjectPlayer();
	GameObjectPlayer(std::string nameObject, std::string nameMesh, std::string nameTexture, std::string nameShader);


	//overwritten virtual functions
	void render();
	void update(float dt);

	//funciones del movimiento
	void roll(float s, float dt);
	void pitch(float s, float dt);
	void accelerate(int sentit);
};