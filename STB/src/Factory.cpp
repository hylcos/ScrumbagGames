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
	if (c != '('){ 
		if (c == 'H'){
			if (!(input >> c)){ throw endOfFile(); }
			if (c != 'U'){
				throw invalidPosition(c);
			}
			if (!(input >> c)){ throw endOfFile(); }
			if (c != 'D'){
				throw invalidPosition(c);
			}
			if (!(input >> c)){ throw endOfFile(); }
			if (c != ':'){
				throw invalidPosition(c);
			}
			throw unknownObject("HUD:");
		}
		if (c == 'L'){
			if (!(input >> c)){ throw endOfFile(); }
			if (c != 'E'){
				throw invalidPosition(c);
			}
			if (!(input >> c)){ throw endOfFile(); }
			if (c != 'V'){
				throw invalidPosition(c);
			}
			if (!(input >> c)){ throw endOfFile(); }
			if (c != 'E'){
				throw invalidPosition(c);
			}
			if (!(input >> c)){ throw endOfFile(); }
			if (c != 'L'){
				throw invalidPosition(c);
			}
			if (!(input >> c)){ throw endOfFile(); }
			if (c != ':'){
				throw invalidPosition(c);
			}
			throw unknownObject("LEVEL:");
		}

		throw invalidPosition(c); 
	}

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
	bool toHud = false;
	std::ifstream input(file);
	try {
		input >> settings;
		for (;;){
			try{
				if (toHud){
					HudController::getInstance().addObjectFromFactory(screen_object_read(input));
				}
				else{
					LevelController::getInstance().addObjectFromFactory(screen_object_read(input));
				}
			}
			catch (unknownObject & exception){
				if (static_cast<std::string>(exception.what()).compare("unknown object [HUD:]") == 0){
					toHud = true;
				}
				if (static_cast<std::string>(exception.what()).compare("unknown object [LEVEL:]") == 0){
					toHud = false;
				}
			}
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
	input.close();
	return settings;
}


Factory::~Factory()
{
}
