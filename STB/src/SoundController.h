//! The sound controller header file
/*!
The header file of the sound controller
*/

#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
class SoundController
{
public:
	// The get instance method of the sound controller
	/*!
	@return a reference to the instance of the sound controller
	*/
	static SoundController& getInstance()
	{
		static SoundController    instance;// Guaranteed to be destroyed.
		instance.load(); 
		// Instantiated on first use.
		return instance;
	}

	//! The file placement of the intro music
	const char* INTRO = "Resources/Sounds/intro.ogg";

	//! The file placement of the outro music
	const char* OUTRO = "Resources/Sounds/outro.ogg";

	//! The load method of the sound controller
	/*!
	Loads the song from the given file location and sets its volume to the volume saved in the settings.
	*/
	void SoundController::load();

	//! THe play music method of the sound controller
	/*!
	This method will play the selected music
	@param file The music that should be played.
	*/
	void SoundController::playMusic(const std::string file );

	//! the set background music method of the sound controller
	/*!
	This method will set the background music on or off
	@param enabled Wether or not the background music should be enabled
	*/
	void SoundController::setBackgroundMusic(bool enabled);

	//! the set background music volume method of the sound controller
	/*!
	This method will set the volume of the background music that is playing
	@param value The level of sound of the background music
	*/
	void SoundController::setBackgroundMusicVolume(int value);

	//! The set sound volume method of the sound controller
	/*!
	This method will set the volume level of all the other sounds in the game
	@param value The level that the volume of the sounds should be set to.
	*/
	void SoundController::setSoundVolume(int value);

	//! The deconstructor of the sound controller class
	/*!
	A default deconstructor
	*/
	~SoundController();

	//! A map saving the name of a song, and a pointer to the sound file
	std::map <  std::string, sf::Music* > map;
private:
	SoundController() {};
	SoundController(SoundController const&) = delete;
	void operator=(SoundController const&) = delete;

	int soundVolume;
	bool isLoaded = false;
	sf::Music bgMusic;
};


