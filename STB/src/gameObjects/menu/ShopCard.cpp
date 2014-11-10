#include "../../stdafx.h"
#include "ShopCard.h"
#include "../Weapon.h"
#include "../../LevelController.h"
#include "../../GameController.h"

ShopCard::ShopCard()
{
	card1 = new WeaponCard{ LevelController::getInstance().getPlayer2()->getWeapons(1)};
	card1->setPosition(sf::Vector2f(50, 10));
	card2 = new WeaponCard{ LevelController::getInstance().getPlayer2()->getWeapons(2)};
	card2->setPosition(sf::Vector2f(250, 10));
	card3 = new WeaponCard{ LevelController::getInstance().getPlayer2()->getWeapons(3)};
	card3->setPosition(sf::Vector2f(450, 10)); 

	timetex = *TextureManager::getInstance().getTexture("HUDObjecten/Timer.png");
	timesprite.setTexture(timetex);

	MoneyText.setFont(*GameController::getInstance().getFont());
	MoneyText.setCharacterSize(20);
	MoneyText.setColor(sf::Color(255, 20, 20));
	MoneyText.setPosition(278, 18);
	MoneyText.setString("00:00");
}

void ShopCard::update(float speedModifier) {
	card1->update(speedModifier);
	card2->update(speedModifier);
	card3->update(speedModifier);
	MoneyText.setPosition(sf::Vector2f(position.x + 23, position.y + 403));
	timesprite.setPosition(sf::Vector2f(position.x, position.y + 400));
	MoneyText.setString(std::to_string(LevelController::getInstance().getPlayer2()->getMoney()));
	LevelController::getInstance().getPlayer2()->setWeapons(card1->getWeapon(), card2->getWeapon(), card3->getWeapon());
}
void ShopCard::draw(sf::RenderWindow & window) const {
	card1->draw(window);
	card2->draw(window);
	card3->draw(window);

	window.draw(timesprite);
	window.draw(MoneyText);
}

ShopCard::~ShopCard()
{
}
