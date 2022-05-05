#pragma once

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
//List of includes to ResourceManager to manage
#include <unordered_map>
#include "mesh.h"
#include "shader.h"
#include "texture.h"
class ResourceManager
{
private:
	//maps for storing handles to pointers to asset objects
	std::unordered_map<std::string, Mesh*> m_meshes;
	std::unordered_map<std::string, Texture*> m_textures;
	std::unordered_map<std::string, Shader*> m_shaders;
	//more lists (audio etc.) will go here later 
	//ToDo: crear las clases de audio...
public:
	//unused constructor and destructor 
	ResourceManager();
	~ResourceManager();
	
	//load assets into memory
	void loadMesh(const std::string, const std::string);
	void loadTexture(const std::string, const std::string);
	void loadShader(const std::string, const std::string, const std::string);

	//unload assets out of memory 
	void unloadMesh(const std::string);
	void unloadTexture(const std::string);
	void unloadShader(const std::string);

	//getters for individual assets
	Mesh* getMesh(const std::string);
	Texture* getTexture(const std::string);
	Shader* getShader(const std::string);

};
#endif