#include "stdafx.h"
#include "GameController.h"
#include "SoundController.h"
#include <SFML/Graphics.hpp>
#include "gameObjects/GameObject.h"
#include "LevelController.h"

#ifdef DEBUG//Defined in GameController.h
#include <iostream>
#endif

void GameController::stop(){
	stopping = true;
}

void GameController::start(){
	SoundController::getInstance().playMusic(SoundController::getInstance().INTRO);
	LevelController::getInstance().startLevel(LevelController::getInstance().MENU_MAIN);
	while (!stopping){
		step();
	}
}

float GameController::getFPS(){
	return fps;
}

sf::RenderWindow& GameController::getWindow(){
	return window;
}

void GameController::step(){
	checkWindow();

	LevelController::getInstance().step(fps, window);
	HudController::getInstance().step(window);
	window.display();

	frames++;

	if (clock() > nextClock){
		nextClock = clock() + CLOCKS_PER_SEC / 3;
		fps = fps / 3 * 2 + (float)frames;

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