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
	if (LevelController::getInstance().getPlayer() != nullptr)
	LevelController::getInstance().getPlayer()->setMoney(0);
	if (LevelController::getInstance().getPlayer2() != nullptr)
	LevelController::getInstance().getPlayer2()->setMoney(0);

	if (LevelController::getInstance().getPlayer() != nullptr){
		LevelController::getInstance().getPlayer()->getWeapons(1)->resetAmmo();
		LevelController::getInstance().getPlayer()->getWeapons(2)->resetAmmo();
		LevelController::getInstance().getPlayer()->getWeapons(3)->resetAmmo();
	}
	if (LevelController::getInstance().getPlayer2() != nullptr){
		LevelController::getInstance().getPlayer2()->getWeapons(1)->resetAmmo();
		LevelController::getInstance().getPlayer2()->getWeapons(2)->resetAmmo();
		LevelController::getInstance().getPlayer2()->getWeapons(3)->resetAmmo();
	}

	LevelController::getInstance().goToNextLevel(&(LevelController::getInstance().LEVEL_ONE));
}

Play::~Play()
{
}
