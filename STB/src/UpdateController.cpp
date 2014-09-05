#include "stdafx.h"
#include "UpdateController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void UpdateController::run(){
	puts("UpdateController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void UpdateController::step(){
}

void runThreadUpdateController(void *){
	UpdateController::getInstance().run();
}

void UpdateController::startThread(){
	_beginthread(runThreadUpdateController, 0, (void*)0);
}
