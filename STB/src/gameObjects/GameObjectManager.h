#pragma once
#include "GameObject.h"
#include "Circle.h"
#include "Logo.h"
#include "Player.h"
#include <string>
#include "Table.h"
#include "Bench.h"
#include "Enemy.h"
#include "menu\play.h"
#include "menu\Options.h"
#include "menu\MainMenu.h"
#include "menu\Checkbox.h"
#include "menu\ToggleMusic.h"

class GameObjectManager
{
public:
	GameObjectManager();

	GameObject * GameObjectManager::createObjectFromName(std::string string);

	~GameObjectManager();
};

