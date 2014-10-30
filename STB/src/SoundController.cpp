#include "stdafx.h"
#include "SoundController.h"
#include "SettingsController.h"

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
	bgMusic.setLoop(true);
	bgMusic.setVolume((float)(SettingsController::getInstance().getSetting(SettingsController::backgroundMusicVolume) * 100 / 255));
	setBackgroundMusic(SettingsController::getInstance().getSetting(SettingsController::backgroundMusic) != 0);
}
void SoundController::playMusic(const std::string file){
	if (!SettingsController::getInstance().getSetting(SettingsController::sounds)){
		return;
	}
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
void SoundController::setBackgroundMusicVolume(int value){
	bgMusic.setVolume((float)(value * 100 / 255));
}

SoundController::~SoundController(){

}