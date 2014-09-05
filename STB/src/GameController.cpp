#include "stdafx.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>

void GameController::stop(){
	stopping = true;
}

void GameController::start(){

	while (!stopping){
		sf::sleep(sf::seconds(1));
	}
}