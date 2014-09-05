#include "stdafx.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include "SoundController.h"

void GameController::stop(){
	stopping = true;
}

int GameController::start(){
	SoundController::getInstance().playMusic();

	while (!stopping){
		sf::sleep(sf::seconds(1));
	}
	return 0;
}

bool GameController::isRunning(){
	return !stopping;
}