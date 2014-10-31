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

Powerup::Powerup(sf::Vector2f position):
GameObject{ gameObjectType::powerup }
{
	sprite.setPosition(position);
	tex = *TextureManager::getInstance().getTexture("Sprites/Powerup.png");
	sprite.setTexture(tex);
	font.loadFromFile("Resources/Fonts/Coalition_v2.ttf");
	poweruptext.setFont(font);
	poweruptext.setCharacterSize(20);
	poweruptext.setColor(sf::Color::Yellow);
	poweruptext.setPosition(200, 200);
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
		poweruptext.setString(PowerupNames[Powerups::ammoUp]);
		LevelController::getInstance().removeObject(this);
		
	}
}

sf::FloatRect Powerup::getBounds() {
	return sprite.getGlobalBounds();
}
void Powerup::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
	sf::View hudView;
	hudView.setCenter(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	hudView.setSize(static_cast<sf::Vector2f>(window.getSize()));
	window.setView(hudView);
	window.draw(poweruptext);
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
void Powerup::pufAmmoUp(){
	LevelController::getInstance().getPlayer()->getSelectedWeapon()->setAmmo(2);
}
void Powerup::pufBAB(){
	ParticleEmitter::amount = 200;
	ParticleEmitter::object = LevelController::getInstance().getPlayer();
	ParticleEmitter::speed = 50.f;
	ParticleEmitter::deceleration = 0.1f;
	ParticleEmitter::direction = rotation;
	ParticleEmitter::directionDeviation = 180.f;
	ParticleEmitter::size = 18.f;
	ParticleEmitter::emitOnce = true;
	ParticleEmitter::setColor(sf::Color::Yellow, 120);
	ParticleEmitter::update(0.f);
	ParticleEmitter::emitOnce = true;
	ParticleEmitter::setColor(sf::Color::Red, 120);
	ParticleEmitter::update(0.f);
	ParticleEmitter::emitOnce = true;
	ParticleEmitter::setColor(sf::Color::Yellow, 120);
	ParticleEmitter::update(0.f);
	ParticleEmitter::emitOnce = true;
	ParticleEmitter::setColor(sf::Color::Black, 120);
	ParticleEmitter::update(0.f);
	ParticleEmitter::emitOnce = true;
	ParticleEmitter::setColor(sf::Color::Red, 120);
	ParticleEmitter::update(0.f);
	ParticleEmitter::emitOnce = true;
	ParticleEmitter::setColor(sf::Color::Yellow, 120);
	ParticleEmitter::update(0.f);
	for (GameObject * obj : LevelController::getInstance().getGameObjects()){
		if (dynamic_cast<Enemy *>(obj) != 0){
			dynamic_cast<Enemy *>(obj)->reduceHP(1000);
		}
	}
}

Powerup::~Powerup(){
}
