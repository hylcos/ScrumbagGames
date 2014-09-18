#include "stdafx.h"
#include "Factory.h"
#include "gameObjects\GameObjectManager.h"
#include "gameObjects\GameObject.h"
#include "GameController.h"
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


void Factory::loadLevel(std::string file, GameController & gameController)
{
	int i = 0;
	std::ifstream input(file);
	try {
		for (;;){
			gameController.addObject(screen_object_read(input));
			i++;
		}
	}
	catch (endOfFile){
		std::cout << i;
		std::cout << " objects loaded\n";
	}
	catch (std::exception & problem){
		std::cout << problem.what();
		char c;
		std::cin >> c;
		exit(0);
	}
}


Factory::~Factory()
{
}
