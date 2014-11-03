#include "../../../stdafx.h"
#include "Upgrade.h"
#include "../../../TextureManager.h"
#include <iostream>
#include "../../../LevelController.h"
#include "../../../GameController.h"

Upgrade::Upgrade(Weapon * weapon,std::string type):
type{ type },
weapon{ weapon }
{
	tex = *TextureManager::getInstance().getTexture("menuObjecten/UpgradeButton.png");
	sprite.setTexture(tex);

	text.setFont(*GameController::getInstance().getFont());
	text.setCharacterSize(10);
	text.setColor(sf::Color(255, 20, 20));
	text.setPosition(position);
	text.setString(type);



	for (int i = 0; i < 5; i++){
		backGround[i] = sf::RectangleShape(sf::Vector2f(10, 20));
		backGround[i].setFillColor(sf::Color::Black);
		backGround[i].setPosition(sf::Vector2f(position.x, position.y - 30));
		foreGround[i] = sf::RectangleShape(sf::Vector2f(10, 20));
		foreGround[i].setFillColor(sf::Color::Yellow);
		foreGround[i].setPosition(sf::Vector2f(position.x, position.y - 30));
	}
}
void Upgrade::update(float speedModifier) {
	for (int i = 0; i < 5; i++){
		backGround[i].setPosition(sf::Vector2f(position.x + (i * 25) - 16, position.y + 30));
		foreGround[i].setPosition(sf::Vector2f(position.x + (i * 25) - 16, position.y + 30));
	}
	text.setPosition(position);
	sprite.setPosition(sf::Vector2f(position.x -16 , position.y));
	if (type == "FireRate"){
		UpgradeLevel = weapon->getFirerateLevel();
	}
	else if (type == "Damage"){
		UpgradeLevel = weapon->getDamageLevel();
	}
	else if (type == "ReloadSpeed"){
		UpgradeLevel = weapon->getReloadSpeedLevel();
	}
	
	Clickable::update();
}

void Upgrade::draw(sf::RenderWindow & window) const {
	for (int i = 0; i < 5; i++){
		window.draw(backGround[i]);
	}
	for (int i = 0; i < UpgradeLevel; i++){
		window.draw(foreGround[i]);
	}

	window.draw(sprite);
	window.draw(text);
	
}
void Upgrade::click() { 
	if (type == "FireRate"){
		weapon->upgradeFireRate();
	}
	else if (type == "Damage"){
		weapon->upgradeDamage();
	}
	else if (type == "ReloadSpeed"){
		weapon->upgradeReloadSpeed();
	}
}
sf::FloatRect Upgrade::getBounds(){
	return sprite.getGlobalBounds();

}

void Upgrade::updateWeapon(Weapon * weapon){
	this->weapon = weapon;

}
Upgrade::~Upgrade()
{
}
