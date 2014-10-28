#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
class SoundController
{
public:
	static SoundController& getInstance()
	{
		static SoundController    instance;
		instance.load();
		return instance;
	}
	
	const char* INTRO = "Resources/Sounds/intro.ogg";
	void SoundController::load();
	//play selected music
	//
	//Call this to start playing the selected music.
	void SoundController::playMusic(const std::string file );

	//step for the controller
	//
	//Executed every step to check change requests in the music
	void SoundController::step();

	void SoundController::setBackgroundMusic(bool enabled);

	~SoundController();

	std::map < std::string, sf::Music* > SoundController::map;
private:
	SoundController() {};
	SoundController(SoundController const&) = delete;
	void operator=(SoundController const&) = delete;

	bool isLoaded = false;
	sf::Music bgMusic;
};


