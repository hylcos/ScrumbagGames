#include "stdafx.h"
#include "LevelController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void LevelController::run(){
	puts("InputController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void LevelController::step(){
}

void runThread(void *){
	LevelController::getInstance().run();
}

void LevelController::startThread(){
	_beginthread(runThread, 0, (void*)0);
}
