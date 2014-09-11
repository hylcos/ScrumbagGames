#include "stdafx.h"
#include "SoundController.h"

#include "GameController.h"
#include <SFML/Audio.hpp>
#include <iostream>


SoundController::SoundController(){
}

void SoundController::step(){
}

void SoundController::playMusic(const char* file){
	std::cout << "Play music";
	bgMusic.openFromFile(file);
	bgMusic.play();
}

SoundController::~SoundController(){

}