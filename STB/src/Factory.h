#pragma once

#include "gameObjects\GameObject.h"
#include "gameObjects\Circle.h"
#include "GameController.h"
#include "Exception.h"

#include <exception>
#include <fstream>
#include <iostream>

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs);
class Factory
{
public:
	Factory();
	void Factory::loadLevel(std::string file, GameController & gameController);
	GameObject * Factory::screen_object_read(std::ifstream & input);
	~Factory();
};

