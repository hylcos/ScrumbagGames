#include "../../../stdafx.h"
#include "WeaponCard.h"
#include "../../../TextureManager.h"
WeaponCard::WeaponCard()
{
}

WeaponCard::WeaponCard(Weapon * weapon):
weapon{ weapon }
{
	tex = *TextureManager::getInstance().getTexture("menuObjecten/WeaponCardBackGround.png");
	sprite.setTexture(tex);
	sprite.setPosition(position);
}

void WeaponCard::update(float speedModifier) {

	sprite.setPosition(position);

}
void WeaponCard::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}

WeaponCard::~WeaponCard()
{
}
