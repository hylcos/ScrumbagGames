//! The settings controller header file
/*!
This is the header file of the settings controller class
*/
#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class SettingsController
{
private:
	SettingsController(){
		if (!loadSettings()){
			createSettings();
		}
		saveSettings();
	};
	SettingsController(SettingsController const&) = delete;
	void operator=(SettingsController const&) = delete;
	sf::Image settings;
	void SettingsController::saveSettings();
	bool SettingsController::loadSettings();
	void SettingsController::createSettings();
	sf::Vector2i SettingsController::toVector2i(int pos);
	int SettingsController::fromVector2i(sf::Vector2i vector);
public:
	//!The getInstance method of the SettingsController
	/*!
	This method makes sure there is only 1 instance of the gamecontroller at a time.
	This way, every time an external class uses a SettingsController, it uses a SettingsController
	with the same attributes as every other class.
	@return The instance of the gamecontroller
	*/
	static SettingsController& getInstance()
	{
		static SettingsController instance;
		return instance;
	}

	//! an enum stating what settings are available to set by this controller.
	enum setting{
		backgroundMusic,
		sounds,
		gore,
		backgroundMusicVolume,
		soundVolume
	};

	//! The get setting method of the setting controller
	/*!
	returns the value of the setting asked by its caller
	@param set What setting the controller wants to know the value of.
	@return the Value of this particular setting
	*/
	int SettingsController::getSetting(setting set);

	//! The set setting method of the settings controller
	/*!
	sets the value of a certain setting
	@param set What setting has to be set
	@param value The value that setting has to be set to.
	*/
	void SettingsController::setSetting(setting set, int value); 

	//! The second set setting method of the settings controller.
	/*!
	Sets the value of a specified setting
	@param set Which setting has to be set
	@param value If the setting has to be set to true or false.
	*/
	void SettingsController::setSetting(setting set, bool value);
};

