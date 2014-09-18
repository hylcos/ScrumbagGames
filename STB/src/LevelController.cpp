#include "stdafx.h"
#include "LevelController.h"
#include "gameObjects/Logo.h"
#include "Factory.h"

LevelController::LevelController()
{
	
}

LevelController::Initializer::Initializer(char randomness, std::string name) :
randomness{ randomness }
{
	Initializer::name = name;
}

void LevelController::startLevel(LevelController::Initializer initializer){
	//gameController->addObject(new Logo());
	Factory factory;
	factory.loadLevel(initializer.name, *this);
}

void LevelController::step(float fps, sf::RenderWindow & window){
	float speedModifier = 60 / fps;

	for (GameObject* obj : gameObjects){
		obj->update(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->move(speedModifier);
	}

	window.clear(sf::Color::White);

	for (GameObject* obj : gameObjects){
		obj->draw(window);
	}

	window.display();
}

void LevelController::addObject(GameObject * object){
	gameObjects.push_back(object);
}

void LevelController::removeObject(GameObject * object){
	if (object == nullptr){
		return;
	}
	delete object;
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}


LevelController::~LevelController()
{
	for (GameObject* obj : gameObjects){
		obj->~GameObject();
	}
}
