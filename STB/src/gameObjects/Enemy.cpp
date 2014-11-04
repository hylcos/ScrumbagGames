#include "../stdafx.h"
#include "../Factory.h"
#include "Enemy.h"
#include "Powerup.h"
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
Animation{enemy}
{
	
}

Enemy::Enemy(Initializer  initializer) :
Animation{}
{

	type = initializer;

}

void Enemy::reduceHP(int damage){
	dmg += damage;
	if (dmg > type.getHP()){
		//Particles
		ParticleEmitter::object = this;
		ParticleEmitter::amount = 50;
		ParticleEmitter::emitOnce = true;
		ParticleEmitter::setColor(sf::Color::Red, 150);
		ParticleEmitter::speed = 2.f;
		ParticleEmitter::minimumSpeed = 0.0001f;
		ParticleEmitter::size = 8.f;
		ParticleEmitter::deceleration = 0.04f;
		ParticleEmitter::directionDeviation = 180;
		ParticleEmitter::isGore = true;
		ParticleEmitter::update(0.f);


		LevelController::getInstance().removeObject(this);
		if (rand() % 2 == 1){
			if (rand() % 3 == 1){
				Powerup* pu = new Powerup(sf::Vector2f{ position });
				int i = rand() % 4 + 1;
				pu->setNumber(i);
				switch (i){
				case 1:
					pu->setType(&pu->puSprint);
					std::cout << "SPRINT \n"; break;
				case 2:
					pu->setType(&pu->puFullHealth);
					std::cout << "FULLHealth \n"; break;
				case 3:
					pu->setType(&pu->puAmmoUp);
					std::cout << "Ammo up (2 magazines)\n"; break;
				case 4:
					pu->setType(&pu->BAB);
					std::cout << "BIGG ASS BOMBUH\n"; break;
				}
				LevelController::getInstance().addObject(pu);
			}
		}
		else {
			Powerup* pu = new Powerup(sf::Vector2f{ position });
			pu->setType(&pu->Money);
			std::cout << "Money NBitches";
			LevelController::getInstance().addObject(pu);
		}
	}
}

void Enemy::update(float speedModifier){
	if (hitCooldown < 0){
	Player* player = LevelController::getInstance().getPlayer();

	setRotation(atan2(position.y - player->getPosition().y, position.x - player->getPosition().x) * 180 / (float)PI - 90);
	toNext += speedModifier;
	melee.setRotation(atan2(position.y - player->getPosition().y, position.x - player->getPosition().x) * 180 / (float)PI - 90);
	melee.setPosition(position);
	sf::Vector2f posDifference = position - player->getPosition();
	float distance = sqrt(pow(posDifference.x, 2) + pow(posDifference.y, 2));
	
		if (distance < 32){
			player->reduceHP(type.getDamage());
			hitCooldown = type.getAttackSpeed();
			drawMelee = true;
		}
	}
	if ((hitCooldown - ( type.getAttackSpeed() *0.75)) < 0)
		drawMelee = false;
	hitCooldown -= speedModifier;
	Animation::update(speedModifier);
}

void Enemy::draw(sf::RenderWindow & window) const{
	Animation::draw(window);
	if (drawMelee)
		window.draw(melee);
}

void Enemy::move(float speedModifier){
	if (hitCooldown- ( type.getAttackSpeed() / 2)< 0){
		Player* player = LevelController::getInstance().getPlayer();
		sf::Vector2f posDifference = position - player->getPosition();
		float distance = sqrt(pow(posDifference.x, 2) + pow(posDifference.y, 2));
		if (distance > 24){
			position.x += (cos((Animation::rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
			position.y += (sin((Animation::rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
		}
		else if (distance < 16){
			position.x -= (cos((Animation::rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
			position.y -= (sin((Animation::rotation - 90)*(float)PI / 180.0f)*speedModifier)*type.getMovementSpeed();
		}
	}
}
void Enemy::setType(Initializer initializer){
	type = initializer;
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/3.png"), 
		*TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/4.png"));
	tex = *TextureManager::getInstance().getTexture("Sprites/Enemies/" + initializer.getName() + "/melee.png");
	melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
}
Enemy::~Enemy()
{
}
