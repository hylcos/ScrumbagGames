#include "stdafx.h"
#include "GameController.h"
//#include "LevelController.h"
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

}

GameController::~GameController(){};