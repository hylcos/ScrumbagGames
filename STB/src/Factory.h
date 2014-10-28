//! The factory header file
/*!
This is the header file of the factory class, the class where all game objects
needed for the game are read from a text file.
*/
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
	//! TODO: enum shit idk
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

	//! The constructor of the factory class
	/*!
	default constructor, also initializes the gameObjectManager.
	*/
	Factory();

	//! The loadLevel method of the factory
	/*!
	Loads the level from a text file. Puts all items in the map based on the terror level.
	Also loads all objects to the HUD.
	@param file The file in which all the game objects are stored.
	@return the value of the terror level.
	*/
	int Factory::loadLevel(std::string file);

	//! The screen_object_read method of the factory
	/*!
	Reads values from a text file and puts them together to create an object.
	@param input The stream from which the factory has to read the values for the object
	@param toHud wether or not the object should be placed on the HUD
	@return the Object created with all the values read from the input stream
	*/
	GameObject * Factory::screen_object_read(std::ifstream & input, bool toHud);

	//! The deconstructor of the factory
	/*!
	the default deconstructor
	*/
	~Factory();
private:
	GameObjectManager gameObjectManager;
};