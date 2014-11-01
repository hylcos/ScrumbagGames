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
	if (string == "Trashcan"){
		return new Trashcan();
	}
	if (string == "Table"){
		return new Table();
	}
	if (string == "Enemy"){
		return new Enemy();
	}
	if (string == "Dunken"){
		return new dunkenBoss();
	}
	if (string == "ParticleManager"){
		return new ParticleManager();
	}
	if (string == "menu/Play"){
		return new Play();
	}
	if (string == "menu/Options"){
		return new Options();
	}
	if (string == "menu/MainMenu"){
		return new MainMenu();
	}
	if (string == "menu/Checkbox"){
		return new Checkbox();
	}
	if (string == "menu/ToggleMusic"){
		return new ToggleMusic();
	}
	if (string == "menu/ToggleSound"){
		return new ToggleSound();
	}
	if (string == "menu/ToggleGore"){
		return new ToggleGore();
	}
	if (string == "menu/MusicSlider"){
		return new MusicSlider();
	}
	if (string == "menu/SoundSlider"){
		return new SoundSlider();
	}
	if (string == "menu/ShopCard"){
		return new ShopCard();
	}
	if (string == "menu/NextRound"){
		return new NextRound();
	}
	if (string == ""){
		throw endOfFile();
	}
	throw unknownObject(string);
}

GameObjectManager::~GameObjectManager()
{
}
