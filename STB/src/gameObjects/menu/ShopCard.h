//! The shop card header file
/*!
This is the header filde of the shop card.
*/
#pragma once

#include "../GameObject.h"
#include "shop/WeaponCard.h"

class ShopCard : public GameObject
{
public:
	//! The constructor of the shop card class
	/*!
	The constructor will load in all the buttons and text used to create a shop card. The shop card is what you see in the shop, consisting of all the upgrade buttons and statistics of a weapon.
	*/
	ShopCard();

	//! The update method of the shop card
	/*!
	The update method will set all the positions of the components of the shop card.
	@param speedModifier A value representing the speed of the game, based on the frames per second.
	*/
	void ShopCard::update(float speedModifier) override;

	//! The drawn method of the shop card.
	/*!
	@param window The window on which the buttons and text have to be drawn.
	*/
	void ShopCard::draw(sf::RenderWindow & window) const override;

	//! The deconstructor of the shop card
	/*!
	A default deconstructor
	*/
	~ShopCard();
private:
	WeaponCard * card1;
	WeaponCard * card2;
	WeaponCard * card3;
	sf::Text MoneyText;
	sf::Texture timetex;
	sf::Sprite timesprite;
};

