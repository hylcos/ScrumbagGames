#include "stdafx.h"
#include "GameController.h"
#include "SoundController.h"
#include <SFML/Graphics.hpp>
#include "gameObjects/GameObject.h"
#include "LevelController.h"

#ifdef DEBUG//Defined in GameController.h
#include <iostream>
#endif

GameController::GameController(SoundController & soundController) :
soundController{ soundController }
{}

void GameController::stop(){
	stopping = true;
}

void GameController::start(){
	soundController.playMusic(soundController.INTRO);
	LevelController::getInstance().startLevel(LevelController::getInstance().LEVEL_ONE);
	while (!stopping){
		step();
	}
}

void GameController::step(){
	checkWindow();

	LevelController::getInstance().step(fps, window);

	frames++;

	if (clock() > nextClock){
		nextClock = clock() + CLOCKS_PER_SEC / 10;
		fps = fps / 10 * 9 + (float)frames;

#ifdef DEBUG//Defined in GameController.h
		std::cout << fps << "\n";
#endif

		frames = 0;
	}
}

void GameController::checkWindow(){
	sf::Event event;
	if (!window.isOpen()){
		stop();
		return;
	}
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed){
			stop();
			return;
		}
	}
}

GameController::~GameController(){
};