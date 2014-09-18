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

void LevelController::startLevel(LevelController::Initializer initializer, GameController & gameController){
	//gameController->addObject(new Logo());
	Factory factory;
	factory.loadLevel(initializer.name, gameController);
}

LevelController::~LevelController()
{
}
