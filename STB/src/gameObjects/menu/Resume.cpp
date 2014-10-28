#include "../../stdafx.h"
#include "Resume.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


Resume::Resume()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/OptionsButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
}

void Resume::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void Resume::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect Resume::getBounds(){
	return sprite.getGlobalBounds();
}

void Resume::click(){
	LevelController::getInstance().setPaused();
}



Resume::~Resume()
{
}