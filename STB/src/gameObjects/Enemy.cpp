#include "../stdafx.h"
#include "Enemy.h"
#include "../LevelController.h"

Enemy::Initializer::Initializer(std::string name){
	Initializer::name = name;
}
std::string Enemy::Initializer::getName(){
	return name;
}

Enemy::Enemy(){
	sf::Texture *tex = TextureManager::getInstance().getTexture("Sprites/Enemies/Average/1.png");
	sprite.setTexture(*tex);
	sprite.setOrigin(tex->getSize().x / 2.0f, tex->getSize().y / 2.0f);
}

Enemy::Enemy(Enemy::Initializer initializer)
{
	sf::Texture *tex = TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/1.png");
	sprite.setTexture(*tex);
	sprite.setOrigin(tex->getSize().x / 2.0f, tex->getSize().y / 2.0f);
}

void Enemy::update(float speedModifier){
	LevelController& levelController = LevelController::getInstance();
	Player* player = levelController.getPlayer();

	sprite.setRotation(atan2(position.y - player->getPosition().y, position.x - player->getPosition().x) * 180 / 3.14159265358979323846f - 90);
}

void Enemy::move(float speedModifier){
	sprite.setPosition(position);
}

void Enemy::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

Enemy::~Enemy()
{
}
