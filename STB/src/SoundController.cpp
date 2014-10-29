#include "stdafx.h"
#include "SoundController.h"

#include <SFML/Audio.hpp>
#include <iostream>


/*void SoundController::step(){
}*/

void SoundController::load(){
	if (isLoaded){
		return;
	}
	isLoaded = true;
	bgMusic.openFromFile(INTRO);
	bgMusic.play();
	bgMusic.setLoop(true);
}
void SoundController::playMusic(const std::string file){
	std::map<std::string, sf::Music*>::iterator it = map.find(file);
	if (it != map.end())
	{
		it->second->play();
	}
	sf::Music* temp = new sf::Music();
	temp->openFromFile("Resources/Sounds/" + file + ".ogg");
	map.insert(std::pair<std::string, sf::Music*>(file, temp));
	it = map.find(file);
	it->second->play();
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