#include "stdafx.h"
#include "Factory.h"
#include "gameObjects\GameObjectManager.h"
#include "gameObjects\GameObject.h"
#include "LevelController.h"
#include "Exception.h"

#include <exception>
#include <fstream>
#include <iostream>

Factory::Factory()
{
	gameObjectManager = GameObjectManager{};
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs){
	char c;
	if (!(input >> c)){ throw endOfFile(); }
	if (c != '('){ throw invalidPosition(c); }

	if (!(input >> rhs.x)){ throw endOfFile(); }


	if (!(input >> c)){ throw endOfFile(); }
	if (c != ','){ throw invalidPosition(c); }

	if (!(input >> rhs.y)){ throw endOfFile(); }

	if (!(input >> c)){ throw endOfFile(); }
	if (c != ')'){ throw invalidPosition(c); }

	return input;
}



// reads one line form the input and returns a pointer to
// the corresponding screen object (allocated on the heap)
GameObject * Factory::screen_object_read(std::ifstream & input){
	sf::Vector2f position;
	std::string name;
	input >> position >> name;
	GameObject * gameObject = gameObjectManager.createObjectFromName(name);
	gameObject->setPosition(position);
	return gameObject;
}


int Factory::loadLevel(std::string file)
{
	int i = 0;
	int settings = 0;
	std::ifstream input(file);
	try {
		input >> settings;
		for (;;){
			LevelController::getInstance().addObject(screen_object_read(input));
			i++;
		}
	}
	catch (endOfFile){
		std::cout << i;
		std::cout << " objects loaded\nLevel settings:" << settings <<'\n';
	}
	catch (std::exception & problem){
		std::cout << problem.what();
		char c;
		std::cin >> c;
		exit(0);
	}
	return settings;
}


Factory::~Factory()
{
}
