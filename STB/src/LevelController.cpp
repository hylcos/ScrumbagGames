#include "stdafx.h"
#include "LevelController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void LevelController::run(){
	puts("LevelController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void LevelController::step(){
}

void runThreadLevelController(void *){
	LevelController::getInstance().run();
}

void LevelController::startThread(){
	_beginthread(runThreadLevelController, 0, (void*)0);
}
