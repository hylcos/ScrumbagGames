#include "../stdafx.h"
#include "Enemy.h"
#include "../LevelController.h"
#include <iostream>

Enemy::Initializer::Initializer(std::string name, float movementSpeed, int hp, bool melee, int damage, float attackSpeed) :
movementSpeed{ movementSpeed },
hp{hp},
melee{ melee },
damage{ damage },
attackSpeed{attackSpeed}
{
	Initializer::name = name;
}
std::string Enemy::Initializer::getName(){
	return name;
}
float Enemy::Initializer::getMovementSpeed(){
	return movementSpeed;
}
int Enemy::Initializer::getHP(){
	return hp;
}
bool Enemy::Initializer::isMelee(){
	return melee;
}
int Enemy::Initializer::getDamage(){
	return damage;
}
float Enemy::Initializer::getAttackSpeed(){
	return attackSpeed;
}


Enemy::Enemy() :
Animation{}
{
	
}

void Enemy::reduceHP(int damage){
	dmg += damage;
	if (dmg > type.getHP()){
		LevelController::getInstance().removeObject(this);
	}
}

Enemy::Enemy(Initializer  initializer) :
Animation{}
{
	
	type = initializer;

}

void Enemy::update(float speedModifier){
	Player* player = LevelController::getInstance().getPlayer();

	setRotation(atan2(position.y - player->getPosition().y, position.x - player->getPosition().x) * 180 / (float)PI - 90);
	toNext += speedModifier;

	sf::Vector2f posDifference = position - player->getPosition();
	float distance = sqrt(pow(posDifference.x, 2) + pow(posDifference.y, 2));
	if (distance < 32){
		if (hitCooldown < 0){
			player->reduceHP(type.getDamage());
			hitCooldown = type.getAttackSpeed();
		}
	}
	hitCooldown -= speedModifier;
	Animation::update(speedModifier);
}

void Enemy::draw(sf::RenderWindow & window) const{
	Animation::draw(window);
}

void Enemy::move(float speedModifier){
	Player* player = LevelController::getInstance().getPlayer();
	sf::Vector2f posDifference = position - player->getPosition();
	float distance = sqrt(pow(posDifference.x, 2) + pow(posDifference.y, 2));
	if (distance > 24){
		position.x += (cos((rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
		position.y += (sin((rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
	}
	else if (distance < 16){
		position.x -= (cos((rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
		position.y -= (sin((rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
	}
}
void Enemy::setType(Initializer initializer){
	type = initializer;
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/3.png"), 
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/4.png"));
}
Enemy::~Enemy()
{
}
