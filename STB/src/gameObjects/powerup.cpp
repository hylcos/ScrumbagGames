#include "../stdafx.h"
#include "powerup.h"
#include "../LevelController.h"

powerup::Types::Types(powerups type, void (*action)()) :
type{ type },
action{action}
{}

void powerup::Types::executeAction(){
	action();
}

powerup::powerup(sf::Vector2f position,int pwr)
{

	sprite.setPosition(position);
	if (!pwr)
		pwr = rand() % last;
	power = static_cast<powerups>(pwr);
	tex = *TextureManager::getInstance().getTexture("Sprites/Powerup.png");
	sprite.setTexture(tex);

}
sf::FloatRect powerup::getBounds() {
	return sprite.getGlobalBounds();
}
void powerup::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
powerups powerup::getPowerup(){
	return power;
}
powerup::~powerup()
{
}
