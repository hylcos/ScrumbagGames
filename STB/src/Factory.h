#pragma once

#include "gameObjects\GameObjectManager.h"
#include "gameObjects\GameObject.h"
#include "LevelController.h"
#include "Exception.h"

#include <exception>
#include <fstream>
#include <iostream>

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs);

class Factory
{
public:
	enum levelSettings{
		/*	Usage:
			bits:	0000000011111111: terror level (0-255)
			bit:	0000000100000000: random (256)
			bit:	0000001000000000: unused (512)
			bit:	0000010000000000: unused (1024)
			bit:	0000100000000000: unused (2048)
			bit:	0001000000000000: unused (4096)
			bit:	0010000000000000: unused (8192)
			bit:	0100000000000000: unused (16384)
			bit:	1000000000000000: unused (32768)
			Calculating the level setting value:
				add all values and settings together, and write this to the first line of the .level file.
			Calculating if an option is set:
				(settings & option) == option
			Calculating if multiple options are set:
				(settings & (option1 | option2 | option3)) == option1 | option2 | option3
		*/
		//256
		//2-512
		//3-1024
		//4-2048
		//5-4096
		//6-8192
		//7-16384
		//8-32768
		random = 256
	};
	Factory();
	int Factory::loadLevel(std::string file);
	GameObject * Factory::screen_object_read(std::ifstream & input, bool toHud);
	~Factory();
private:
	GameObjectManager gameObjectManager;
};