#include "stdafx.h"
#include "Factory.h"
#include "gameObjects\GameObject.h"
#include "gameObjects\Circle.h"
#include "GameController.h"

#include <exception>
#include <fstream>
#include <iostream>

Factory::Factory()
{
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
	if (name == "CIRCLE"){
		sf::Color color;
		float randomness;
		input >> randomness;

		return new Circle{ position, randomness };
	}/*
	else if (name == "RECTANGLE"){
		sf::Color color;
		float size;
		input >> color >> size;

		return new rectangle{ position, (int)size, color
		};
	}*/
	/*else if (name == "IMAGE"){
		std::string name;
		input >> name;
		return new image(position, name);
	}*/
	else if (name == ""){
		throw endOfFile();
	}
	throw unknownObject(name);
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
