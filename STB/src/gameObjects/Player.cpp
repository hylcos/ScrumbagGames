#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"
#include <iostream>
#include "../LevelController.h"
#include "powerup.h"
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
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Players/Player-1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-4.png"));
	setWeapons(new Gun("Sprites/Weapons/pistol", 25, 90.0, 8,8, 350, 2,30), new Gun("Sprites/Weapons/uzi", 25, 90.0, 120,30, 350, 2,15), new Gun{ "Sprites/Weapons/shotgun", 25,180.0, 60,6, 350, 10,45 });
}

void Player::reduceHP(int damage){
	if (!invincible){
		hp -= damage;
		if (hp < 0){
			std::cout << "You're pretty dead...\n";
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

	for (GameObject* gameObject : LevelController::getInstance().getGameObjects()){
		if (dynamic_cast<powerup*>(gameObject) != 0){
			if (gameObject->getBounds().intersects(Animation::getBounds())){
				powerup* p = dynamic_cast<powerup*>(gameObject);
				switch (p->getPowerup()) {
					case doubleDamage :
						break;
					case doubleReloadSpeed:
						break;
					case BAB:
						for (GameObject* gameObject : LevelController::getInstance().getGameObjects())
							if (dynamic_cast<Enemy*>(gameObject) != 0)
								LevelController::getInstance().removeObject(gameObject);
						break;
					case invincibility:
						invincible = true;
						invincibleTimer = 300;
						break;
					case instaKill:
						break;
					case sprint:
						doubleSpeedTimer = 300;
						speed = 2;
						break;
					case slowMotion:
						break;
					case miniGun:
						break;
					case sniperVision:
						break;
					case frenzy:
						break;
					case clone:
						break;
					case flamethrower:
						break;
					case doubleSpawn:
						break;
					case fog:
						break;
					case jam:
						break;
					case blind:
						break;

				}

				
				LevelController::getInstance().removeObject(gameObject);
			}
		}
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
		position.x += cos(dir) * speedModifier * speed;
		position.y += sin(dir) * speedModifier * speed;
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

void Player::doubleSpeed(){
	doubleSpeedTimer = 300;
	speed = 5;
}
void Player::fullHealth(){
	hp = 100;
}

Player::~Player()
{
	for each(Weapon * weapon in selectedWeapons)
		delete weapon;

}
