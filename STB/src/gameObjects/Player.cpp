#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"
#include <iostream>
#include "../LevelController.h"
#include "Powerup.h"
#include "WeaponManager.h"
struct { sf::Keyboard::Key key; float x; float y; } actions[] = {
		{ sf::Keyboard::A, -1.0, 0.0 },
		{ sf::Keyboard::D, 1.0, 0.0 },
		{ sf::Keyboard::W, 0.0, -1.0 },
		{ sf::Keyboard::S, 0.0, 1.0 }
};
struct { sf::Keyboard::Key key; int weapon; } weaponchoice[]{
		{ sf::Keyboard::Num1, 0 },
		{ sf::Keyboard::Num2, 1 },
		{ sf::Keyboard::Num3, 2 }
};
Player::Player() :
Animation{player}
{
	
	WeaponManager::getInstance().load();
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Players/Player-1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-4.png"));
	sf::sleep(sf::milliseconds(1000));
	std::cout << "Oh hello you!!";
	setWeapons(WeaponManager::getInstance().pistol, WeaponManager::getInstance().rifle, WeaponManager::getInstance().shotgun);
	std::cout << "\n" << selectedWeapons[0]->getType() << "\n";
	std::cout << "\n" << selectedWeapons[1]->getType() << "\n";
	std::cout << "\n" << selectedWeapons[2]->getType() << "\n";
}

void Player::reduceHP(int damage){
	if (!invincible){
		hp -= damage;
		if (hp <= 0){
			LevelController::getInstance().goToNextLevel(&LevelController::getInstance().MENU_MAIN);
		}
	}
}

void Player::update(float speedModifier) {
	Animation::update(speedModifier);
	selectedWeapons[curWeapon]->setRotation(rotation);
	selectedWeapons[curWeapon]->setPosition(position);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		selectedWeapons[curWeapon]->fire();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		selectedWeapons[curWeapon]->reload();

	for (auto & choice : weaponchoice)
		if (sf::Keyboard::isKeyPressed(choice.key))
			curWeapon = choice.weapon; 

	doubleSpeedTimer -= speedModifier;
	if (doubleSpeedTimer <= 0)
		speed = 1;
	if (invincibleTimer <= 0)
		invincible = false;
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
		newPos = position;
		rotation = dir * 180 / 3.14159265358979323846f + 90;
		newPos.x += cos(dir) * speedModifier * speed;
		newPos.y += sin(dir) * speedModifier * speed;
		for (GameObject * obj : LevelController::getInstance().getGameObjects()){
			if (sqrt(pow(newPos.x - obj->getPosition().x, 2) + pow(newPos.y - obj->getPosition().y, 2)) > 128){
				continue;
			}
		

		
		/*	sf::Vector2f topLeft = obj->getTransform().transformPoint(sf::Vector2f(0, 0));
			sf::Vector2f topRight = obj->getTransform().transformPoint(sf::Vector2f(static_cast<float>(obj->getSize().x), 0));
			sf::Vector2f bottomLeft = obj->getTransform().transformPoint(sf::Vector2f(0, static_cast<float>(obj->getSize().y)));
			sf::Vector2f bottomRight = obj->getTransform().transformPoint(sf::Vector2f(static_cast<float>(obj->getSize()).x), static_cast<float>(obj->getSize().y)));
			*/
			if (obj->getType() == bench /*&& one.vertex.getBounds().contains(newPos)*/){
				isOnBench = true;
				
			}

		}
		if (!(newPos.x < 32 + 16 || newPos.x > 1248 -16|| newPos.y < 32 +16 || newPos.y > 934-16)){

			position = newPos;
		}


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
int Player::getHp(){
	return hp;
}

float Player::getAmmo(){
	return getSelectedWeapon()->getAmmo();
}
void Player::doubleSpeed(){
	doubleSpeedTimer = 300;
	speed = 5;
}
void Player::fullHealth(){
	hp = 100;
}

Player::~Player()
{
	

}
