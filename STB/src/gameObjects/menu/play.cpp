#include "../../stdafx.h"
#include "Play.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


Play::Play()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/PlayButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
};

void Play::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void Play::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect Play::getBounds(){
	return sprite.getGlobalBounds();
}

void Play::click(){
	LevelController::getInstance().reset();
	LevelController::getInstance().goToNextLevel(&(LevelController::getInstance().LEVEL_ONE));
}

Play::~Play()
{
}
