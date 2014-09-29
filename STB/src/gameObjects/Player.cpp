#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"
#include <iostream>

struct { sf::Keyboard::Key key; float x; float y; } actions[] = {
	{ sf::Keyboard::A, -1.0, 0.0 },
	{ sf::Keyboard::D, 1.0, 0.0 },
	{ sf::Keyboard::W, 0.0, -1.0 },
	{ sf::Keyboard::S, 0.0, 1.0 }
};

Player::Player() :
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Players/Player-1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-4.png"));
	setWeapons(new Gun("Sprites/Weapons/pistol", 25, 2.0, 100, 350, 2), new Gun("Sprites/Weapons/pistol", 25, 2.0, 100, 350, 2), new Gun{ "Sprites/Weapons/pistol", 25, 2.0, 100, 350, 2 });
}

void Player::update(float speedModifier) {
	curSprite = *Animation::getCurrentAnimation();
	curSprite.setPosition(position);
	selectedWeapons[curWeapon]->setPosition(position);
	curSprite.setRotation(rotation);
	if (toNext >= 10){
		Animation::next();
		toNext -= 10;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		selectedWeapons[curWeapon]->fire();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		curWeapon = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		curWeapon = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		curWeapon = 2;
}

void Player::move(float speedModifier){
	sf::Vector2f newPos{ 0, 0 };
	for (auto & action : actions){
		if (sf::Keyboard::isKeyPressed(action.key)){
			newPos.x += action.x;
			newPos.y += action.y;
		}
	}
	if (newPos != sf::Vector2f{ 0, 0 }){
		float dir = atan2(newPos.y, newPos.x);
		rotation = dir * 180 / 3.14159265358979323846f + 90;
		position.x += cos(dir) * speedModifier;
		position.y += sin(dir) * speedModifier;
		toNext += speedModifier;
	}

}
void Player::draw(sf::RenderWindow & window) const {
	selectedWeapons[curWeapon]->draw(window);
	window.draw(curSprite);
}
void Player::setRotation(float rotation){
	Player::rotation = rotation;
}
void Player::setWeapons(Weapon * weapon1, Weapon * weapon2, Weapon * weapon3){
	selectedWeapons[0] = weapon1;
	selectedWeapons[1] = weapon2;
	selectedWeapons[2] = weapon3;
}
Weapon * Player::getSelectedWeapon(){
	return selectedWeapons[curWeapon];
}
Player::~Player()
{
	for each(Weapon * weapon in selectedWeapons)
		delete weapon;

}
