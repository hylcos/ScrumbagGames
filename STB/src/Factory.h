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
	Factory();
	void Factory::loadLevel(std::string file, LevelController & levelController);
	GameObject * Factory::screen_object_read(std::ifstream & input);
	~Factory();
private:
	GameObjectManager gameObjectManager;
};

