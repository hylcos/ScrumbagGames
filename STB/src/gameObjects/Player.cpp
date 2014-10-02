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
	setWeapons(new Gun("Sprites/Weapons/pistol", 25, 2.0, 100, 350, 2), new Gun("Sprites/Weapons/uzi", 25, 2.0, 100, 350, 2), new Gun{ "Sprites/Weapons/shotgun", 25, 2.0, 100, 350, 2 });
}

void Player::reduceHP(int damage){
	hp -= damage;
	if (hp < 0){
		std::cout << "You're pretty dead...\n";
	}
}

void Player::update(float speedModifier) {
	Animation::update(speedModifier);
	selectedWeapons[curWeapon]->setRotation(rotation);
	selectedWeapons[curWeapon]->setPosition(position);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		selectedWeapons[curWeapon]->fire();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
		curWeapon = 0; std::cout << curWeapon << "\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
		curWeapon = 1; std::cout << curWeapon << "\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
		curWeapon = 2; std::cout << curWeapon << "\n";
	}
	selectedWeapons[curWeapon]->update(speedModifier);
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
	Animation::draw(window);
	selectedWeapons[curWeapon]->draw(window);
}
void Player::setRotation(float rotation){
	Player::rotation = rotation;
	Animation::setRotation(rotation);
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
