#include "../stdafx.h"
#include "Knife.h"
#include "../LevelController.h"
#include <iostream>
Knife::Knife(std::string name, int damage, short attackSpeed, int range):
	damage{ damage },
	attackSpeed{ attackSpeed },
	range{ range }
{
	Knife::name = name;
	tex = *TextureManager::getInstance().getTexture("Sprites/Weapons/" + name + ".png");
	sprite.setTexture(tex);
	sprite.setOrigin(tex.getSize().x / 2.0f, tex.getSize().x*1.5f);
	texmelee = *TextureManager::getInstance().getTexture("Sprites/Weapons/" + name + "_hit.png");
	melee.setTexture(texmelee);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().x*1.5f);
}

void Knife::fire(){
	if (hitCooldown <= 0){
		drawMelee = true;
		hitCooldown = attackSpeed;
		SoundController::getInstance().playMusic("knife_hit"+ std::to_string(rand() % 2 + 1));
		sf::Vector2f point{ 
			position.x 
			+ 11 * cos(melee.getRotation() * PI / 180) 
			+ (range* 2)* cos((melee.getRotation() - 90) * PI / 180),
			position.y 
			+ 11 * sin(melee.getRotation() * PI / 180) 
			+ (range * 2) * sin((melee.getRotation() - 90) * PI / 180) };
		for (GameObject* gameObject : LevelController::getInstance().getGameObjects()){
			if (dynamic_cast<Enemy*>(gameObject) != 0){
				if (gameObject->getBounds().contains(point)){
					ParticleEmitter::spawnPosition = gameObject->getPosition();
					ParticleEmitter::amount = (int)(damage / 2);
					ParticleEmitter::emitOnce = true;
					ParticleEmitter::setColor(sf::Color::Red, 200);
					ParticleEmitter::speed = 30.f;
					ParticleEmitter::minimumSpeed = 0.0001f;
					ParticleEmitter::size = 4.f;
					ParticleEmitter::deceleration = 0.3f;
					ParticleEmitter::directionDeviation = 180;
					ParticleEmitter::isGore = true;
					ParticleEmitter::emitParticles();
					dynamic_cast<Enemy*>(gameObject)->reduceHP(damage);
				}
			}
		}
	}
	
}

void Knife::update(float speedModifier) {
	hitCooldown -= speedModifier;
	if (hitCooldown < attackSpeed *0.8){
		drawMelee = false;
	}
	sprite.setPosition(position);
	melee.setPosition(position);
	ParticleEmitter::update(0.f);
}

void Knife::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
	if (drawMelee){
		window.draw(melee);
	}
}

void Knife::setRotation(float rotation){
	sprite.setRotation(rotation);
	melee.setRotation(rotation);
}
std::string Knife::getName(){
	return name;
}
int Knife::getDamageLevel() {
	return damageLevel;
}
void Knife::upgradeDamage() {
	if (damageLevel < 5){
		float betweenStep = static_cast<float>(damage)* 1.25f;
		damage = static_cast<int>(betweenStep);
		damageLevel++;
	}
}

int Knife::getFirerateLevel() {
	return fireRateLevel;
}
void Knife::upgradeFireRate() {
	if (fireRateLevel < 5){
		float betweenStep = static_cast<float>(attackSpeed) / 1.10f;
		attackSpeed = static_cast<short>(betweenStep);
		fireRateLevel++;
	}
}

int Knife::getReloadSpeedLevel() {
	return reloadSpeedLevel;
}
void Knife::upgradeReloadSpeed() {

}



std::string Knife::getInfo() {
	std::string info;
	info += "Name: " + name + "\n";
	info += "Damage: " + std::to_string(damage) + "\n";
	info += "AttackSpeed: " + std::to_string(attackSpeed) + "\n";
	info += "Range: " + std::to_string(range) + "\n";
	return info;
}
