#include "../../stdafx.h"
#include "Shop.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


Shop::Shop()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/ShopButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
};

void Shop::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void Shop::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect Shop::getBounds(){
	return sprite.getGlobalBounds();
}

void Shop::click(){
	LevelController::getInstance().getPlayer()->setNextRound(false);
	LevelController::getInstance().goToNextLevel(&(LevelController::getInstance().SHOP));
}

Shop::~Shop()
{
}
