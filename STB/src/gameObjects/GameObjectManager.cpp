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
	if (string == ""){
		throw endOfFile();
	}
	throw unknownObject(string);
}

GameObjectManager::~GameObjectManager()
{
}
