#include "../stdafx.h"
#include "powerup.h"


powerup::powerup(sf::Vector2f position)
{
	p = static_cast<powerups>(rand() % last);
	tex = *TextureManager::getInstance().getTexture("Sprites/Powerup.png");
	sprite.setTexture(tex);

}


powerup::~powerup()
{
}
