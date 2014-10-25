#include "../stdafx.h"
#include "Knife.h"
#include "../LevelController.h"

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
		sf::Vector2f point{ 
			position.x 
			+ 11 * cos(melee.getRotation() * PI / 180) 
			+ 21 * cos((melee.getRotation() - 90) * PI / 180), 
			position.y 
			+ 11 * sin(melee.getRotation() * PI / 180) 
			+ 21 * sin((melee.getRotation() - 90) * PI / 180) };
		for (GameObject* gameObject : LevelController::getInstance().getGameObjects()){
			if (dynamic_cast<Enemy*>(gameObject) != 0){
				if (gameObject->getBounds().contains(point)){
					dynamic_cast<Enemy*>(gameObject)->reduceHP(damage);
				}
			}
		}
	}
	
}

void Knife::setRotation(float rotation){
	sprite.setRotation(rotation);
	melee.setRotation(rotation);
}

void Knife::update(float speedModifier) {
	hitCooldown -= speedModifier;
	if (hitCooldown < attackSpeed *0.8){
		drawMelee = false;
	}
	sprite.setPosition(position);
	melee.setPosition(position);
}

void Knife::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
	if (drawMelee){
		window.draw(melee);
	}
}