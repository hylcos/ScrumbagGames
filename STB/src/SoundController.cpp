#include "stdafx.h"
#include "SoundController.h"

#include "GameController.h"
#include <SFML/Audio.hpp>
#include <iostream>

SoundController::SoundController(){
}

void SoundController::step(){
}

void SoundController::playMusic(){
	std::cout << "Play music";
	bgMusic.openFromFile("Resources/Sounds/intro.ogg");
	bgMusic.play();
}

SoundController::~SoundController(){

}