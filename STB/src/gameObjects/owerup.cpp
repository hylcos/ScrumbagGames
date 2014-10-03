#include "../stdafx.h"
#include "Powerup.h"
#include "../LevelController.h"

Powerup::Types::Types(Powerups type, void (*action)()) :
type{ type },
action{action}
{}

void Powerup::Types::executeAction(){
	action();
}

Powerup::Powerup(sf::Vector2f position,int pwr)
{

	sprite.setPosition(position);
	if (!pwr)
		pwr = rand() % last;
	power = static_cast<Powerups>(pwr);
	tex = *TextureManager::getInstance().getTexture("Sprites/Powerup.png");
	sprite.setTexture(tex);

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
Powerup::~Powerup()
{
}
