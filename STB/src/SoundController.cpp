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

SoundController::~SoundController(){

}