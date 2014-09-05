#include "stdafx.h"
#include "SoundController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void SoundController::run(){
	puts("InputController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void SoundController::step(){
}

void runThread(void *){
	SoundController::getInstance().run();
}

void SoundController::startThread(){
	_beginthread(runThread, 0, (void*)0);
}
