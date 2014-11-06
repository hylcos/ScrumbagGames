#include "Particle.h"
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
Animation{ player }
{
	//Particle Emitter
	ParticleEmitter::amount = 6;
	ParticleEmitter::frequency = 10;
	ParticleEmitter::setColor(sf::Color::Black, 120);
	ParticleEmitter::object = this;
	ParticleEmitter::speed = 5.f;
	ParticleEmitter::deceleration = 0.15f;
	ParticleEmitter::directionDeviation = 180.f;
	ParticleEmitter::size = 3.f;
	gameOver = false;
	WeaponManager::getInstance().load();
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Players/Player-1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-4.png"));
	setWeapons(WeaponManager::getInstance().dagger, WeaponManager::getInstance().pistol, WeaponManager::getInstance().shotgun);

}

void Player::reduceHP(int damage){
	if (!invincible){
		SoundController::getInstance().playMusic("Ouch_" + std::to_string(rand() % 2 + 1));
		hp -= damage;
		if (hp <= 0){
			gameOver = true;
			gameOverTimer = 500;
		}
	}
}
bool Player::getgameOver(){
	return gameOver;
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
		if (sf::Keyboard::isKeyPressed(choice.key)){
			curWeapon = choice.weapon;
		}
	gameOverTimer -= speedModifier;
	doubleSpeedTimer -= speedModifier;
	if (doubleSpeedTimer <= 0)
		speed = 3;
	if (invincibleTimer <= 0)
		invincible = false;
	if (gameOverTimer <= 0 && gameOver){
		gameOver = false;
		LevelController::getInstance().goToNextLevel(&LevelController::getInstance().MENU_MAIN);

	}
	LevelController::getInstance().setZoom(selectedWeapons[curWeapon]->getName() == "sniper"?1.5f:1.f);
	selectedWeapons[curWeapon]->update(speedModifier);

	ParticleEmitter::update(speedModifier);
}

void Player::move(float speedModifier){
	framesTillNextParticle++;
	sf::Vector2f newPos{ 0, 0 }, reservePos{ position };

	for (auto & action : actions){
		if (sf::Keyboard::isKeyPressed(action.key)){
			newPos.x += action.x;
			newPos.y += action.y;
		}
	}
	emit = false;
	{//Calculate newpos
		if (newPos == sf::Vector2f{ 0, 0 }){
			return;
		}
		float dir = atan2(newPos.y, newPos.x);
		newPos.x = (cos(dir) * speedModifier * speed);
		newPos.y = (sin(dir) * speedModifier * speed);
	}
	position += newPos;
	curSprite.setPosition(position);
	{//Calculate all collisions
		//Calculate collisions with trashcans
		for (GameObject * obj : LevelController::getInstance().getGameObjects()){
			if (obj->getType() != GameObject::gameObjectType::trashcan){
				continue;
			}
			if (32 > sqrt(pow(obj->getPosition().x - position.x, 2) + pow(obj->getPosition().y - position.y, 2))){
				//If the distance is smaller than 32, collide with bin
				position = reservePos;
				return;
			}
		}

		bool collidesWithBench = false;
		if (!isOnTable){
			//Calculate collision with benches
			for (GameObject * obj : LevelController::getInstance().getGameObjects()){
				if (obj->getType() != GameObject::gameObjectType::bench){
					continue;
				}
				if (Collision::collision(this, obj)){
					collidesWithBench = true;
				}
			}
		}

		if (!isOnTable && collidesWithBench){//set isOnTable if colliding with both a table and a bench.
			for (GameObject * obj : LevelController::getInstance().getGameObjects()){
				if (obj->getType() != GameObject::gameObjectType::table){
					continue;
				}
				if (Collision::collision(this, obj)){
					isOnTable = true;
				}
			}
		}

		if (isOnTable){//Reset isOnTable if not on a table
			isOnTable = false;
			for (GameObject * obj : LevelController::getInstance().getGameObjects()){
				if (obj->getType() != GameObject::gameObjectType::table){
					continue;
				}
				if (Collision::collision(this, obj)){
					isOnTable = true;
				}
			}
		}

		if (!isOnTable){//Stop moving if not on a table but colliding with one.
			for (GameObject * obj : LevelController::getInstance().getGameObjects()){
				if (obj->getType() != GameObject::gameObjectType::table){
					continue;
				}
				if (Collision::collision(this, obj)){
					position = reservePos;
					return;
				}
			}
		}
	}

	if (((position.x < 32 + 16 || position.x > 1248 - 16 || position.y < 32 + 6 || position.y > 934 - 16))){
		position = reservePos;
	}
	if (position != reservePos){
		emit = true;
		toNextWalkSound += speedModifier;
		toNext += speedModifier;
		if (toNextWalkSound >= 20){
			walkSound++;
			if (walkSound == 9){
				walkSound = 1;
			}
			SoundController::getInstance().playMusic("walk_" + std::to_string(rand() % 8 + 1));
			toNextWalkSound -= 20;
		}
	}
	/*
	if (newPos != sf::Vector2f{ 0, 0 }){
		emit = true;
		bool isOnBench = false;
		bool isWalkeble = true;
		bool collided = false;
		GameObject * closestTable = nullptr;
		float closestTableDistance = 128.0f*128.0f;
		sf::Vector2f closestCollisionPoint;

		float dir = atan2(newPos.y, newPos.x);
		newPos = position;
		reservePos = position;
		//rotation = dir * 180 / PI + 90;
		position.x += (cos(dir) * speedModifier * speed) * 2;
		position.y += (sin(dir) * speedModifier * speed) * 2;

		curSprite.setPosition(position);
		for (GameObject * obj : LevelController::getInstance().getGameObjects()){
			if (sqrt(pow(newPos.x - obj->getPosition().x, 2) + pow(newPos.y - obj->getPosition().y, 2)) > 128){
				continue;
			}

			if (obj->getType() == bench && Collision::collision(this, obj)){
				isOnBench = true;
				collided = true;
			}
			if (obj->getType() == trashcan && Collision::collision(this, obj)){
					collided = true;
					isWalkeble = false;
			}
			if (obj->getType() == table && Collision::collision(this, obj)){
				if (isOnBench || isOnTable){
					isOnTable = true;
					collided = true;
				}
				else {
					if (Collision::dist2(Collision::getClosestPoint(obj, this), newPos) < closestTableDistance){
						closestCollisionPoint = Collision::getClosestPoint(obj, this);
						closestTableDistance = Collision::dist2(closestCollisionPoint, newPos);
						closestTable = obj;
					}
					isWalkeble = false;
				}
			}

		}
		if (!collided){
			isOnTable = false;
		}

		position.x -= (cos(dir) * speedModifier * speed);
		position.y -= (sin(dir) * speedModifier * speed);

		isWalkeble &= (!(position.x < 32 + 16 || position.x > 1248 - 16 || position.y < 32 + 6 || position.y > 934 - 16));
		if (position.x < 32 + 16 || position.x > 1248 - 16 || position.y < 32 + 6 || position.y > 934 - 16){
			emit = false;
			
		}
		else {
			if (toNextWalkSound >= 20){
				walkSound++;
				if (walkSound == 9){
					walkSound = 1;
				}
				SoundController::getInstance().playMusic("walk_" + std::to_string(rand() % 8 + 1));
				toNextWalkSound -= 20;
			}
		}

		if (!isWalkeble){
			position = reservePos;
			emit = false;
			float dirToPoint = atan2(closestCollisionPoint.y - position.y, closestCollisionPoint.x - position.x) * 180 / PI;
			float playerDir = dir * 180 / PI;
			float newDir = playerDir;
			if (playerDir == dirToPoint || playerDir > fmodf(dirToPoint + 90,360.f) || playerDir < fmodf(dirToPoint - 90 + 360,360.f)){
				goto exit;
			}
			if (playerDir < dirToPoint){
				newDir = dirToPoint - 90;
			}
			else{
				newDir = dirToPoint + 90;
			}
			float spd = abs(playerDir - dirToPoint) / 90;
			position.x += (cos(newDir * PI / 180) * speedModifier * spd);
			position.y += (sin(newDir * PI / 180) * speedModifier * spd);
			float newClosestTableDistance = closestTableDistance;
			GameObject * newClosestTable = closestTable;

			for (GameObject * obj : LevelController::getInstance().getGameObjects()){
				if (sqrt(pow(newPos.x - obj->getPosition().x, 2) + pow(newPos.y - obj->getPosition().y, 2)) > 128){
					continue;
				}
				if (obj->getType() == table && Collision::collision(this, obj)){
					if (Collision::dist2(Collision::getClosestPoint(obj, this), newPos) < newClosestTableDistance){
						closestTableDistance = Collision::dist2(closestCollisionPoint, newPos);
						closestTable = obj;
					}
				}

			}
			if (newClosestTable != closestTable){
				position = reservePos;
				emit = false;
			}
		}
		exit:
		if (((position.x < 32 + 16 || position.x > 1248 - 16 || position.y < 32 + 6 || position.y > 934 - 16))){
			position = reservePos;
		}
		toNextWalkSound += speedModifier;
		toNext += speedModifier;
	}

	*/

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

Weapon * Player::getWeapons(int value){
	return selectedWeapons[value-1];
}
int Player::getHp(){
	return hp;
}
void Player::addMoney(int money){
	this->money += money;
}

void Player::setMoney(int money){
	this->money = money;
}
int Player::getMoney(){
	return money;
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

sf::Vector2u Player::getSize(){

	return sf::Vector2u{ static_cast<unsigned int>(getBounds().width), static_cast<unsigned int>(getBounds().height) };
}
void Player::setNextRound(bool value){
	nextRound = value;
}
bool Player::getNextRound(){
	return nextRound;
}
Player::~Player()
{


}
