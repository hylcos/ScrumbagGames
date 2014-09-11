#include "stdafx.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>

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