#include "../stdafx.h"
#include "Knife.h"
#include "../LevelController.h"
#include <iostream>
Knife::Knife(std::string name, float damage, short attackSpeed, int range):
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
					dynamic_cast<Enemy*>(gameObject)->reduceHP(static_cast<int>(damage)* (doubleDamageEnabled ? 2 : 1));
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
	doubleDamageTimer -= speedModifier;
	if (doubleDamageTimer <= 0 && doubleDamageEnabled){
		doubleDamageEnabled = false;
	}
}
void Knife::doubleDamage(){
	doubleDamageEnabled = true;
	doubleDamageTimer = 360;
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
		damage *= 1.10f;

		damageLevel++;
	}
}

int Knife::getFirerateLevel() {
	return fireRateLevel;
}
void Knife::upgradeFireRate() {
	if (fireRateLevel < 5){
		attackSpeed /= 1.10f;
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
	info += "Damage: " + std::to_string(static_cast<int>(damage)) + "\n";
	info += "AttackSpeed: " + std::to_string(static_cast<int>(attackSpeed)) + "\n";
	info += "Range: " + std::to_string(range) + "\n";
	return info;
}

void Knife::reset(){
	for (fireRateLevel; fireRateLevel > 0; fireRateLevel--){
		attackSpeed *= 1.10f;
	}
	for (damageLevel; damageLevel > 0; damageLevel--){
		damage /= 1.10f;
	}
}
