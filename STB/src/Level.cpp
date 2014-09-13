#include "stdafx.h"
#include "Level.h"
#include "gameObjects/Logo.h"


Level::Level()
{
}

Level::Initializer::Initializer(char randomness) :
randomness{ randomness }
{
}

void Level::startLevel(Level::Initializer initializer, GameController * gameController){
	gameController->addObject(new Logo());
}

Level::~Level()
{
}
