#include "stdafx.h"
#include "SoundController.h"

#include "GameController.h"
#include <SFML/Audio.hpp>
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

void SoundController::playMusic(){
	bgMusic.openFromFile("Resources/Sounds/intro.ogg");
	bgMusic.play();
}