#pragma once
#ifndef GAMEOBJECTLIGHT_H
#define GAMEOBJECTLIGHT_H
#include "GameObject.h"
class GameObjectLight : public GameObject
{
public:
	GameObjectLight();
	//~GameObjectLight : public GameObject{();
	void render();
	void update(float dt);

};
#endif // !GAMEOBJECTLIGHT_H
