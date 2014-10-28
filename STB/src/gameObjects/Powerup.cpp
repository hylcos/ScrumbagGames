#include "../stdafx.h"
#include "Powerup.h"
#include "../LevelController.h"

Powerup::Types::Types(Powerups type, void(Powerup::*action)()) :
type{ type },
action{ action }
{}

void Powerup::Types::executeAction(Powerup & powerup){
	Player* player = LevelController::getInstance().getPlayer();
	(powerup.*action)();
}

Powerup::Powerup(sf::Vector2f position, int pwr):
GameObject{ gameObjectType::powerup }
{

	sprite.setPosition(position);
	if (!pwr)
		pwr = rand() % last;
	power = static_cast<Powerups>(pwr);
	tex = *TextureManager::getInstance().getTexture("Sprites/Powerup.png");
	sprite.setTexture(tex);

}

Powerup* Powerup::setType(Powerup::Types* type){
	this->type = type;
	return this;
}

void Powerup::update(float speedModifier){
	sf::Vector2f diff = sprite.getPosition() - LevelController::getInstance().getPlayer()->getPosition();
	float dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
	if (dist < 32){
		type->executeAction(*this);
		LevelController::getInstance().removeObject(this);
	}
}

sf::FloatRect Powerup::getBounds() {
	return sprite.getGlobalBounds();
}
void Powerup::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
Powerups Powerup::getPowerup(){
	return power;
}

void Powerup::pufDoubleSpeed(){
	LevelController::getInstance().getPlayer()->doubleSpeed();
}
void Powerup::pufFullHealth(){
	LevelController::getInstance().getPlayer()->fullHealth();
}
void Powerup::pufBAB(){
	for (GameObject * obj : LevelController::getInstance().getGameObjects()){
		if (dynamic_cast<Enemy *>(obj) != 0){
			dynamic_cast<Enemy *>(obj)->reduceHP(1000);
		}
	}
}

Powerup::~Powerup(){
}
