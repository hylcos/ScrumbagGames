#include "../stdafx.h"
#include "Enemy.h"
#include "../LevelController.h"

Enemy::Initializer::Initializer(std::string name){
	Initializer::name = name;
}
std::string Enemy::Initializer::getName(){
	return name;
}

Enemy::Enemy() :
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Enemies/Average/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/Average/2.png"));
}

Enemy::Enemy(Enemy::Initializer initializer) :
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/2.png"));
}

void Enemy::update(float speedModifier){
	Player* player = LevelController::getInstance().getPlayer();

	setRotation(atan2(position.y - player->getPosition().y, position.x - player->getPosition().x) * 180 / 3.14159265358979323846f - 90);
	Animation::update(speedModifier);
}

void Enemy::draw(sf::RenderWindow & window) const{
	window.draw(curSprite);
}

Enemy::~Enemy()
{
}
