#pragma once

#include "gameObjects\GameObjectManager.h"
#include "gameObjects\GameObject.h"
#include "LevelController.h"
#include "Exception.h"

#include <exception>
#include <fstream>
#include <iostream>

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs);

class LevelController;
class Factory
{
public:
	enum levelSettings{
		//256
		//2-512
		//3-1024
		//4-2048
		//5-4096
		//6-8192
		//7-16384
		//8-32768
		random = 512
	};
	Factory();
	int Factory::loadLevel(std::string file, LevelController & levelController);
	GameObject * Factory::screen_object_read(std::ifstream & input);
	~Factory();
private:
	GameObjectManager gameObjectManager;
};

