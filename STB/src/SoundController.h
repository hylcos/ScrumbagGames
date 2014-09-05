#pragma once
#include <SFML/Audio.hpp>
class SoundController
{
public:
	//------SINGLETON-----//
	//getInstance returns the instance of ViewController. Used to call most functions.
	//
	//getInstance is used to return the instance of ViewController. This is used to prevent multiple instances of this controller to be made. 
	//@return ViewController instance;
	static SoundController& getInstance()
	{
		static SoundController    instance;
		return instance;
	}

	//startThread, used to start the thread of the ViewController.
	//
	//startThread starts the thread the ViewController uses to draw everything.
	void SoundController::startThread();

	//run, do not call!
	//
	//run is the function that actually does everything the ViewController has to do. Do not call this, instead use startThread()!
	void SoundController::run();
	//------END OF SINGLETON------//

	//play selected music
	//
	//Call this to start playing the selected music.
	void playMusic();
private:
	//------SINGLETON-----//
	SoundController() {}
	SoundController(SoundController const&); // Don't Implement.
	void operator=(SoundController const&); // Don't implement.
	//------END OF SINGLETON------//

	void SoundController::step();

	sf::Music bgMusic;
};


