#pragma once
#include "GameObject.h"
#include "Circle.h"
#include "Logo.h"
#include "Player.h"
#include <string>

class GameObjectManager
{
public:
	GameObjectManager();

	GameObject * GameObjectManager::createObjectFromName(std::string string);

	~GameObjectManager();
};

