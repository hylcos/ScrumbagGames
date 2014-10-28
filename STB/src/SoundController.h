#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class SoundController
{
public:
	static SoundController& getInstance()
	{
		static SoundController    instance;
		return instance;
	}
	
	const char* INTRO = "Resources/Sounds/intro.ogg";

	//play selected music
	//
	//Call this to start playing the selected music.
	void SoundController::playMusic(const char* file);

	//step for the controller
	//
	//Executed every step to check change requests in the music
	void SoundController::step();

	void SoundController::setBackgroundMusic(bool enabled);

	~SoundController();
private:
	SoundController() {};
	SoundController(SoundController const&) = delete;
	void operator=(SoundController const&) = delete;

	sf::Music bgMusic;
};


