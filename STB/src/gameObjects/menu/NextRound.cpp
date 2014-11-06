#include "../../stdafx.h"
#include "NextRound.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


NextRound::NextRound()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/PlayButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
};

void NextRound::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void NextRound::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect NextRound::getBounds(){
	return sprite.getGlobalBounds();
}

void NextRound::click(){
	LevelController::getInstance().getPlayer2()->getWeapons(1)->resetAmmo();
	LevelController::getInstance().getPlayer2()->getWeapons(2)->resetAmmo();
	LevelController::getInstance().getPlayer2()->getWeapons(3)->resetAmmo();
	LevelController::getInstance().goToNextRound();
}

NextRound::~NextRound()
{
}
