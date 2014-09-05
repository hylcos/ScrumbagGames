#include "stdafx.h"
#include "InputController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void InputController::run(){
	puts("InputController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void InputController::step(){
}

void runThreadInputController(void *){
	InputController::getInstance().run();
}

void InputController::startThread(){
	_beginthread(runThreadInputController, 0, (void*)0);
}
