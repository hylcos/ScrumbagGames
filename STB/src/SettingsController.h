#pragma once
#include <string>
#include <SFML/Graphics/Image.hpp>
class SettingsController
{
private:
	SettingsController(){
		settings.create((unsigned int)256, (unsigned int)256, sf::Color::White);
		loadSettings();
		saveSettings();
	};
	SettingsController(SettingsController const&) = delete;
	void operator=(SettingsController const&) = delete;
	sf::Image settings;
	void SettingsController::saveSettings();
	void SettingsController::loadSettings();
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

	enum setting{
		backgroundMusic
	};
	int SettingsController::getSetting(setting set);
	void SettingsController::setSetting(setting set, int value);
};

