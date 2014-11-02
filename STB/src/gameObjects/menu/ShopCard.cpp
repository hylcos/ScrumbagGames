#include "../../stdafx.h"
#include "ShopCard.h"
#include "../Weapon.h"
#include "../../LevelController.h"


ShopCard::ShopCard()
{
	card1 = new WeaponCard{ LevelController::getInstance().getPlayer2()->getWeapons(1)};
	card1->setPosition(sf::Vector2f(50, 10));
	card2 = new WeaponCard{ LevelController::getInstance().getPlayer2()->getWeapons(2)};
	card2->setPosition(sf::Vector2f(250, 10));
	card3 = new WeaponCard{ LevelController::getInstance().getPlayer2()->getWeapons(3)};
	card3->setPosition(sf::Vector2f(450, 10));
}

void ShopCard::update(float speedModifier) {
	card1->update(speedModifier);
	card2->update(speedModifier);
	card3->update(speedModifier);
	LevelController::getInstance().getPlayer2()->setWeapons(card1->getWeapon(), card2->getWeapon(), card3->getWeapon());
}
void ShopCard::draw(sf::RenderWindow & window) const {
	card1->draw(window);
	card2->draw(window);
	card3->draw(window);
}

ShopCard::~ShopCard()
{
}
