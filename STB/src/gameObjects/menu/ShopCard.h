#pragma once

#include "../GameObject.h"
#include "WeaponCard.h"

class ShopCard : public GameObject
{
public:
	ShopCard();
	void ShopCard::update(float speedModifier) override;
	void ShopCard::draw(sf::RenderWindow & window) const override;

	~ShopCard();
private:
	WeaponCard * card1;
	WeaponCard * card2;
	WeaponCard * card3;
};

