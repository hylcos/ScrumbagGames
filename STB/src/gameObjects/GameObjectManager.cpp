#include "../stdafx.h"
#include "GameObjectManager.h"
#include "../Exception.h"


GameObjectManager::GameObjectManager()
{
}

GameObject * GameObjectManager::createObjectFromName(std::string string){
	if (string == "Circle"){
		return new Circle();
	}
	if (string == "Logo"){
		return new Logo();
	}
	if (string == "Player"){
		return new Player();
	}
	if (string == "Bench"){
		return new Bench();
	}
	if (string == "Table"){
		return new Table();
	}
	if (string == "Enemy"){
		Enemy* e = new Enemy();
		e->setType(e->cheerleader);
		return e;
	}
	if (string == "menu/Play"){
		return new Play();
	}
	if (string == ""){
		throw endOfFile();
	}
	throw unknownObject(string);
}

GameObjectManager::~GameObjectManager()
{
}
