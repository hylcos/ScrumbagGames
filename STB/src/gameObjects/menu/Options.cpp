#include "../../stdafx.h"
#include "Options.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


Options::Options()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/OptionsButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
}

void Options::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void Options::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect Options::getBounds(){
	return sprite.getGlobalBounds();
}

void Options::click(){
	LevelController::getInstance().goToNextLevel(&(LevelController::getInstance().MENU_OPTIONS));
}



Options::~Options()
{
}
