#include "stdafx.h"
#include "SoundController.h"

#include <SFML/Audio.hpp>
#include <iostream>


/*void SoundController::step(){
}*/

void SoundController::playMusic(const char* file){
	std::cout << "Play music\n";
	bgMusic.openFromFile(file);
	bgMusic.play();
}

void SoundController::setBackgroundMusic(bool enabled){
	if (!enabled){
		bgMusic.stop();
		return;
	}
	bgMusic.play();
}

SoundController::~SoundController(){

}