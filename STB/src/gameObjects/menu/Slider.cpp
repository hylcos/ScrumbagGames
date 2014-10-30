#include "../../stdafx.h"
#include "Slider.h"
#include "../../TextureManager.h"
#include "../../SettingsController.h"

Slider::Slider()
{
	value = SettingsController::getInstance().getSetting(SettingsController::backgroundMusicVolume);
	spriteScrollButton.setTexture(*TextureManager::getInstance().getTexture("menuObjecten/ScrollButton"), true);
	spriteScrollButton.setOrigin(static_cast<sf::Vector2f>(spriteScrollButton.getTexture()->getSize()) / 2.0f);
	spriteScrollBar.setTexture(*TextureManager::getInstance().getTexture("menuObjecten/ScrollBar"), true);
	spriteScrollBar.setOrigin(static_cast<sf::Vector2f>(spriteScrollBar.getTexture()->getSize()) / 2.0f);
}

void Slider::draw(sf::RenderWindow & window) const{
	window.draw(spriteScrollBar);
	window.draw(spriteScrollButton);
}

Slider::~Slider()
{
}
