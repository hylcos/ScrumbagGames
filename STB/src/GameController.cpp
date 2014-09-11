#include "stdafx.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "gameObjects/GameObject.h"

GameController::GameController(SoundController & soundController) :
soundController{ soundController }
{}

void GameController::stop(){
	stopping = true;
}

void GameController::start(){
	soundController.playMusic(soundController.INTRO);
	while (!stopping){
		step();
	}
}

void GameController::step(){
	checkWindow();

	for (int i = gameObjects.size() - 1; i >= 0; i--){

	}

	window.clear(sf::Color::White);

	window.display();

	frames++;

	if (clock() > nextClock){
		nextClock = clock() + CLOCKS_PER_SEC/10;
		fps = fps / 10 * 9 + (float)frames;
		std::cout << fps << "\n";
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

GameController::~GameController(){};