#include "../../stdafx.h"
#include "MainMenu.h"
#include "../../TextureManager.h"
#include "../../LevelController.h"


MainMenu::MainMenu()
{
	tex = TextureManager::getInstance().getTexture("menuObjecten/BackButton.png");
	sprite.setTexture(*tex, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(tex->getSize()) / 2.0f);
}

void MainMenu::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void MainMenu::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect MainMenu::getBounds(){
	return sprite.getGlobalBounds();
}

void MainMenu::click(){
	LevelController::getInstance().goToNextLevel(&(LevelController::getInstance().MENU_MAIN));
}



MainMenu::~MainMenu()
{
}
