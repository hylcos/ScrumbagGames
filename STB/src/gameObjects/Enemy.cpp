#include "../stdafx.h"
#include "Enemy.h"
#include "../LevelController.h"
#include <iostream>

Enemy::Initializer::Initializer(std::string name, float movementSpeed) :
movementSpeed{ movementSpeed }
{
	Initializer::name = name;
}
std::string Enemy::Initializer::getName(){
	return name;
}
float Enemy::Initializer::getMovementSpeed(){
	return movementSpeed;
}

Enemy::Enemy() :
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Enemies/Average/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/Average/2.png"));
	movementSpeed = average.getMovementSpeed();
}

Enemy::Enemy(Enemy::Initializer initializer) :
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/2.png"));
	movementSpeed = initializer.getMovementSpeed();
}

void Enemy::update(float speedModifier){
	Player* player = LevelController::getInstance().getPlayer();

	setRotation(atan2(position.y - player->getPosition().y, position.x - player->getPosition().x) * 180 / 3.14159265358979323846f - 90);
	toNext += speedModifier;
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
		position.x += (cos((rotation - 90)*(float)PI / 180.0f)*speedModifier)*movementSpeed;
		position.y += (sin((rotation - 90)*(float)PI / 180.0f)*speedModifier)*movementSpeed;
	}
	else if (distance < 16){
		position.x -= (cos((rotation - 90)*(float)PI / 180.0f)*speedModifier)*movementSpeed;
		position.y -= (sin((rotation - 90)*(float)PI / 180.0f)*speedModifier)*movementSpeed;
	}
}

Enemy::~Enemy()
{
}
