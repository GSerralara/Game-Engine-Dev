#include "game.h"
#include "utils.h"
#include "mesh.h"
#include "texture.h"
#include "rendertotexture.h"
#include "shader.h"

#include <cmath>

//some globals
float angle = 0;
int okc = 0;
int okb = 0;
int okn = 0;
int cameraType = 0; //0 -> follow, 1 -> free flight
RenderToTexture* rt = NULL;
Game* Game::instance = NULL;
std::vector<GameObject*> allObjects;
int active_lvl = 0;
// Handle the KeyPress event to print the type of character entered into the control.


Game::Game(SDL_Window* window)
{
	this->window = window;
	instance = this;

	// initialize attributes
	// Warning: DO NOT CREATE STUFF HERE, USE THE INIT 
	// things create here cannot access opengl
	SDL_GetWindowSize(window, &window_width, &window_height);
	std::cout << " * Window size: " << window_width << " x " << window_height << std::endl;

	keystate = NULL;
	mouse_locked = false;
}

//Here we have already GL working, so we can create meshes and textures
void Game::init(void)
{
	std::cout << " * Path: " << getPath() << std::endl;

	//SDL_SetWindowSize(window, 50,50);

	//OpenGL flags
	glEnable(GL_CULL_FACE); //render both sides of every triangle
	glEnable(GL_DEPTH_TEST); //check the occlusions using the Z buffer

	//init resourcemanager
	resource_manager = new ResourceManager();

	scenes.push_back(new Scene());
	scenes.push_back(new Scene());
	scenes.push_back(new Scene());
	//scenes.push_back(new Scene());
	

	//init sceneparser
	scene_parser = new SceneParser();
	this->activeScene = scenes[active_lvl];
	scene_parser->parseFile("data/scenes/scene1.rg", activeScene);
	scene_parser->parseFile("data/scenes/scene2.rg", scenes[1]);
	scene_parser->parseFile("data/scenes/scene3.rg", scenes[2]);
	//scene_parser->parseFile("data/scenes/scene4.rg", scenes[3]);

	allObjects = activeScene->root->returnAllCollidableChilds();

	//hide the cursor
	SDL_ShowCursor(!mouse_locked); //hide or show the mouse
}

//what to do when the image has to be draw
void Game::render(void)
{
	//set the clear color (the background color)
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Clear the window and the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//if menu then menu->render()

	activeScene->render();

	//disable blending to draw text on top
	glDisable(GL_BLEND);

	//*** Drawing code ends here ***

	//swap between front buffer and back buffer
	SDL_GL_SwapWindow(this->window);
}

void Game::update(double seconds_elapsed)
{
	double speed = seconds_elapsed * 100; //the speed is defined by the seconds_elapsed so it goes constant

	if (keystate[SDL_SCANCODE_C] && okc == 0) {
		if (cameraType == 0) {
			cameraType = 1;
			std::cout << "Canvi de camera a Third Person" << std::endl;
			okc = 1;
		}
		else {
			cameraType = 0;
			std::cout << "Canvi de camera a Freeroam" << std::endl;
			okc = 1;
		}
	}
	if (!keystate[SDL_SCANCODE_C]) {
		okc = 0;
	}

	if (keystate[SDL_SCANCODE_N] && active_lvl + 1 < scenes.size() && okn == 0) {
		okn = 1;
		active_lvl+=1;
		activeScene = scenes[active_lvl];
	}
	if (!keystate[SDL_SCANCODE_N]) {
		okn = 0;
	}
	if (keystate[SDL_SCANCODE_B] && active_lvl - 1 >= 0 && okb == 0) {
		okb = 1;
		active_lvl--;
		activeScene = scenes[active_lvl];
	}
	if (!keystate[SDL_SCANCODE_B]) {
		okb = 0;
	}

	if (cameraType == 1) {
		//mouse input to rotate the cam
		if ((mouse_state & SDL_BUTTON_LEFT) || mouse_locked) //is left button pressed?
		{
			activeScene->camera->rotate(mouse_delta.x * 0.005f, Vector3(0, -1, 0));
			activeScene->camera->rotate(mouse_delta.y * 0.005f, activeScene->camera->getLocalVector(Vector3(-1, 0, 0)));
		}

		//async input to move the camera around
		if (keystate[SDL_SCANCODE_LSHIFT]) speed *= 10; //move faster with left shift
		if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) activeScene->camera->move(Vector3(0, 0, 1) * (float)speed);
		if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN]) activeScene->camera->move(Vector3(0, 0, -1) * (float)speed);
		if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) activeScene->camera->move(Vector3(1, 0, 0) * (float)speed);
		if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) activeScene->camera->move(Vector3(-1, 0, 0) * (float)speed);
	}
	else if (cameraType == 0) {

		//async input to move the player around
		if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) ((GameObjectPlayer*)activeScene->camera->tofollow)->pitch(1.0, seconds_elapsed);
		if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN]) ((GameObjectPlayer*)activeScene->camera->tofollow)->pitch(-1.0, seconds_elapsed);
		if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) ((GameObjectPlayer*)activeScene->camera->tofollow)->roll(-1.0, seconds_elapsed);
		if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) ((GameObjectPlayer*)activeScene->camera->tofollow)->roll(1.0, seconds_elapsed);


		//such velocity
		if (keystate[SDL_SCANCODE_LSHIFT]) ((GameObjectPlayer*)activeScene->camera->tofollow)->accelerate(1);
		if (keystate[SDL_SCANCODE_LCTRL]) ((GameObjectPlayer*)activeScene->camera->tofollow)->accelerate(-1);

		activeScene->camera->updateFollow();
	}

	//to navigate with the mouse fixed in the middle
	if (mouse_locked)
	{
		int center_x = (int)floor(window_width*0.5f);
		int center_y = (int)floor(window_height*0.5f);
		//center_x = center_y = 50;
		SDL_WarpMouseInWindow(this->window, center_x, center_y); //put the mouse back in the middle of the screen
		//SDL_WarpMouseGlobal(center_x, center_y); //put the mouse back in the middle of the screen

		this->mouse_position.x = (float)center_x;
		this->mouse_position.y = (float)center_y;
	}

	angle += (float)seconds_elapsed * 10;

	////Collisions
	//scene->root->checkColisions();
	//GameObjectMesh* A = (GameObjectMesh*)scene->root->lookInChilds("player1");
	//GameObjectMesh* B = (GameObjectMesh*)scene->root->lookInChilds("teapot_001");

	//A->mesh->collision_model->setTransform(A->model.m);
	//B->mesh->collision_model->setTransform(B->model.m);

	for (int i = 0; i < allObjects.size(); i++) {
		GameObjectMesh* I = (GameObjectMesh*)allObjects[i];
		for (int k = 0; k < allObjects.size(); k++) {
			GameObjectMesh* K = (GameObjectMesh*)allObjects[k];
			if (K != I) {
				I->mesh->collision_model->setTransform(I->model.m);
				K->mesh->collision_model->setTransform(K->model.m);

				bool collision = I->mesh->collision_model->collision(K->mesh->collision_model);

				if (collision) {
					std::cout << "colisio de " << I->name << " amb " << K->name << std::endl;
				}
			}

		}
	}




	//bool collision = A->mesh->collision_model->collision(B->mesh->collision_model);



	//Update final
	activeScene->update(seconds_elapsed);

}

//Keyboard event handler (sync input)
void Game::onKeyPressed(SDL_KeyboardEvent event)
{
	switch (event.keysym.sym)
	{
	case SDLK_ESCAPE: exit(0); //ESC key, kill the app
	}
}


void Game::onMouseButton(SDL_MouseButtonEvent event)
{
	if (event.button == SDL_BUTTON_MIDDLE) //middle mouse
	{
		mouse_locked = !mouse_locked;
		SDL_ShowCursor(!mouse_locked);
	}
}

void Game::setWindowSize(int width, int height)
{
	std::cout << "window resized: " << width << "," << height << std::endl;

	/*
	Uint32 flags = SDL_GetWindowFlags(window);
	if(flags & SDL_WINDOW_ALLOW_HIGHDPI)
	{
		width *= 2;
		height *= 2;
	}
	*/

	glViewport(0, 0, width, height);
	activeScene->camera->aspect = width / (float)height;
	window_width = width;
	window_height = height;
}