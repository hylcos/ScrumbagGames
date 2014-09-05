#include "stdafx.h"
#include "UpdateController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void UpdateController::run(){
	puts("InputController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void UpdateController::step(){
}

void runThread(void *){
	UpdateController::getInstance().run();
}

void UpdateController::startThread(){
	_beginthread(runThread, 0, (void*)0);
}
