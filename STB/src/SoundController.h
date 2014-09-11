#pragma once
#include <SFML/Audio.hpp>
class SoundController
{
public:
	SoundController();

	//play selected music
	//
	//Call this to start playing the selected music.
	void SoundController::playMusic(const char* file);

	//step for the controller
	//
	//Executed every step to check change requests in the music
	void SoundController::step();

	~SoundController();
private:
	sf::Music bgMusic;
};


