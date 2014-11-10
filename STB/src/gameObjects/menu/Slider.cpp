#include "../../stdafx.h"
#include "Slider.h"
#include "../../TextureManager.h"
#include "../../HudController.h"
#include "../../SettingsController.h"
#include <algorithm>
#include <iostream>

Slider::Slider()
{
	spriteScrollButton.setTexture(*TextureManager::getInstance().getTexture("menuObjecten/ScrollButton.png"), true);
	spriteScrollButton.setOrigin(static_cast<sf::Vector2f>(spriteScrollButton.getTexture()->getSize()) / 2.0f);
	spriteScrollBar.setTexture(*TextureManager::getInstance().getTexture("menuObjecten/ScrollBar.png"), true);
	spriteScrollBar.setOrigin(static_cast<sf::Vector2f>(spriteScrollBar.getTexture()->getSize()) / 2.0f);
}

void Slider::update(float speedModifier){
	Clickable::update();
	spriteScrollBar.setPosition(position);
	spriteScrollButton.setPosition((value*spriteScrollBar.getTexture()->getSize().x / 255) + position.x - spriteScrollBar.getTexture()->getSize().x/2, spriteScrollBar.getPosition().y);
	if (!selected){
		return;
	}
	value = std::max(0, std::min(255, static_cast<int>((HudController::getInstance().getMousePos().x - getPosition().x + spriteScrollBar.getTexture()->getSize().x / 2) * 255 / spriteScrollBar.getTexture()->getSize().x)));
}

void Slider::release(){
	if (!selected){
		return;
	}
	updateValue(value);
	selected = false;
}

void Slider::press(){
	selected = true;
}

sf::FloatRect Slider::getBounds(){
	std::cout << spriteScrollBar.getGlobalBounds().width << '|' << spriteScrollBar.getGlobalBounds().height << '\n';
	return spriteScrollBar.getGlobalBounds();
}

void Slider::updateValue(int value){

}

void Slider::draw(sf::RenderWindow & window) const{
	window.draw(spriteScrollBar);
	window.draw(spriteScrollButton);
}

Slider::~Slider()
{
}
