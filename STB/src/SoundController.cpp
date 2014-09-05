#include "stdafx.h"
#include "SoundController.h"

#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <process.h>

void SoundController::run(){
	puts("SoundController started");

	while (GameController::getInstance().isRunning()){
		step();
	}
}

void SoundController::step(){
}

void runThreadSoundController(void *){
	SoundController::getInstance().run();
}

void SoundController::startThread(){
	_beginthread(runThreadSoundController, 0, (void*)0);
}
