#include "../stdafx.h"
#include "Powerup.h"
#include "../LevelController.h"
#include "Player.h"

Powerup::Types::Types(Powerups type, void(Powerup::*action)()) :
type{ type },
action{ action }
{

}
void Powerup::setText(std::string powerupstring){

}

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

}

Powerup* Powerup::setType(Powerup::Types* type){
	this->type = type;
	if (type == &Money){
		tex = *TextureManager::getInstance().getTexture("Sprites/money.png");
	}
	return this;
}

void Powerup::setNumber(int& number){
	powerupnumber = number;
}

void Powerup::update(float speedModifier){
	sf::Vector2f diff = sprite.getPosition() - LevelController::getInstance().getPlayer()->getPosition();
	float dist = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
	poweruptext.setPosition(LevelController::getInstance().getPlayer()->getPosition().x, LevelController::getInstance().getPlayer()->getPosition().y-100);
	if (dist < 32 && !isLoaded){
		type->executeAction(*this);
		std::cout << "PRINT";
		showtextTimer = 300;
		if (type != &Money){
			poweruptext.setString(PowerupNames[powerupnumber]);
			poweruptext.setOrigin(poweruptext.getLocalBounds().width / 2, poweruptext.getLocalBounds().top);
		}
		isLoaded = true;
		
	}
	if (isLoaded){
		showtextTimer -= speedModifier;
		poweruptext.setColor(sf::Color::Color(255, 255, 0, sf::Uint8(std::min(255.f,showtextTimer))));
		if (showtextTimer <= 0){
			poweruptext.setString("");
			LevelController::getInstance().removeObject(this);
		}
	}
	

}

sf::FloatRect Powerup::getBounds() {
	return sprite.getGlobalBounds();
}
void Powerup::draw(sf::RenderWindow & window) const {
	if (!isLoaded)
		window.draw(sprite);
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
void Powerup::addMoney(){
	LevelController::getInstance().getPlayer()->addMoney(rand() % 25 + 25);
}

Powerup::~Powerup(){
}
