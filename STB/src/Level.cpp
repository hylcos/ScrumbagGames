#include "stdafx.h"
#include "Level.h"
#include "gameObjects/circle.h"


Level::Level()
{
}

Level::Initializer::Initializer(char randomness) :
randomness{ randomness }
{
}

void Level::startLevel(Level::Initializer initializer, GameController * gameController){
	//gameController->addObject(new Circle());
}

Level::~Level()
{
}
