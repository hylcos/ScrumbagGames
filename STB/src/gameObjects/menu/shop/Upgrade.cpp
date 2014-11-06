#include "../../../stdafx.h"
#include "Upgrade.h"
#include "../../../TextureManager.h"
#include <iostream>
#include "../../../LevelController.h"
#include "../../../GameController.h"

Upgrade::Upgrade(Weapon * weapon,types type):
type{ type },
weapon{ weapon }
{
	Upgrade::type = type;
	tex = *TextureManager::getInstance().getTexture("menuObjecten/UpgradeButton.png");
	sprite.setTexture(tex);

	text.setFont(*GameController::getInstance().getFont());
	text.setCharacterSize(10);
	text.setColor(sf::Color(255, 20, 20));
	text.setPosition(position);
	if (type == types::FireRate){
		text.setString("Fire rate");
	}
	else if (type == types::Damage){
		text.setString("Damage");
	}
	else if (type == types::ReloadSpeed){
		text.setString("Reload speed");
	}



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
	if (type == types::FireRate){
		UpgradeLevel = weapon->getFirerateLevel();
	}
	else if (type == types::Damage){
		UpgradeLevel = weapon->getDamageLevel();
	}
	else if (type == types::ReloadSpeed){
		UpgradeLevel = weapon->getReloadSpeedLevel();
	}
	
	Clickable::update();
}

void Upgrade::draw(sf::RenderWindow & window) const {
	if (UpgradeLevel != 6){
		for (int i = 0; i < 5; i++){
			window.draw(backGround[i]);
		}
		for (int i = 0; i < UpgradeLevel; i++){
			window.draw(foreGround[i]);
		}

		window.draw(sprite);
		window.draw(text);
	}
	
}
void Upgrade::click() { 
	if (LevelController::getInstance().getPlayer2()->getMoney() >= ((UpgradeLevel + 1) * 100) && UpgradeLevel != 5){
		if (type == types::FireRate){
			weapon->upgradeFireRate();
		}
		else if (type == types::Damage){
			weapon->upgradeDamage();
		}
		else if (type == types::ReloadSpeed){
			weapon->upgradeReloadSpeed();
		}
		LevelController::getInstance().getPlayer2()->setMoney(LevelController::getInstance().getPlayer2()->getMoney() - ((UpgradeLevel + 1) * 100));
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
