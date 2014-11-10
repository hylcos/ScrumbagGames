#include "stdafx.h"
#include "SettingsController.h"


void SettingsController::saveSettings(){
	settings.saveToFile("settings.png");
}

bool SettingsController::loadSettings(){
	return settings.loadFromFile("settings.png");
}
void SettingsController::createSettings(){
	settings.create((unsigned int)256, (unsigned int)256, sf::Color::White);
	settings.saveToFile("settings.png");
}

int SettingsController::fromVector2i(sf::Vector2i vector){
	return (vector.x + vector.y * 255);
}

sf::Vector2i SettingsController::toVector2i(int pos){
	return sf::Vector2i{ pos % 255, (pos / 255) % 255 };
}

int SettingsController::getSetting(setting set){
	loadSettings();
	sf::Color pixel = settings.getPixel(toVector2i(set).x, toVector2i(set).y);
	return pixel.r + pixel.g * 256 + pixel.b * 256 * 256;
}

void SettingsController::setSetting(setting set, int value){
	loadSettings();
	settings.setPixel(toVector2i(set).x, toVector2i(set).y, sf::Color{ (sf::Uint8)(value % 256), (sf::Uint8)((value / 256) % 256), (sf::Uint8)((value / 256 / 256) % 256), (sf::Uint8)255 });
	saveSettings();
}

void SettingsController::setSetting(setting set, bool value){
	int val = (value ? 255 : 0);
	loadSettings();
	settings.setPixel(toVector2i(set).x, toVector2i(set).y, sf::Color{ (sf::Uint8)(val % 256), (sf::Uint8)((val / 256) % 256), (sf::Uint8)((val / 256 / 256) % 256), (sf::Uint8)255 });
	saveSettings();
}