#include "../../stdafx.h"
#include "ShopCard.h"
#include "../Weapon.h"
#include "../../LevelController.h"


ShopCard::ShopCard()
{
	card1 = new WeaponCard{ LevelController::getInstance().getPlayer()->getWeapons(1) };

	card2 = new WeaponCard{ LevelController::getInstance().getPlayer()->getWeapons(2) };

	card3 = new WeaponCard{ LevelController::getInstance().getPlayer()->getWeapons(3) };
}

void ShopCard::update(float speedModifier) {

}
void ShopCard::draw(sf::RenderWindow & window) const {
}

ShopCard::~ShopCard()
{
}
