#include "stdafx.h"
#include "LevelController.h"
#include "gameObjects/Logo.h"


LevelController::LevelController()
{
}

LevelController::Initializer::Initializer(char randomness) :
randomness{ randomness }
{
}

void LevelController::startLevel(LevelController::Initializer initializer, GameController * gameController){
	gameController->addObject(new Logo(*this));
}

LevelController::~LevelController()
{
}
