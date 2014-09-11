#include "stdafx.h"
#include "GameController.h"
//#include "LevelController.h"
#include <SFML/Graphics.hpp>

GameController::GameController(){};

void GameController::stop(){
	stopping = true;
}

void GameController::start(){
	while (!stopping){
		step();
	}
}

void GameController::step(){

}

GameController::~GameController(){};