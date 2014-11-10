#include "../../stdafx.h"
#include "Tutorial.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


Tutorial::Tutorial()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/TutorialButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
};

void Tutorial::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void Tutorial::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect Tutorial::getBounds(){
	return sprite.getGlobalBounds();
}

void Tutorial::click(){
	

	LevelController::getInstance().goToNextLevel(&(LevelController::getInstance().TUTORIAL));
}

Tutorial::~Tutorial()
{
}
