//! The Weapon Card header file
/*!
This is the header file of the weapon card class
*/
#pragma once
#include "../../Weapon.h"
#include "Upgrade.h"
#include "switchWeapon.h"
class WeaponCard : public GameObject
{
public:
	//! The weapon card constructor
	/*!
	The default constructor.
	*/
	WeaponCard();

	//! The second constructor of the weapon card
	/*!
	The constructor we mainly use.
	This method creates the 'card' you see in the shop.
	It wil load in all the textures and buttons needed.
	@param weapon The weapon for which the card has to be created
	*/
	WeaponCard::WeaponCard(Weapon * weapon);

	//! The update method of the weapon card
	/*!
	This method sets all the positions of the textures and buttons on the card.
	It also checks if the card needs to switch with the other available card on it's slot in the shop.
	@param speedModifier A value representing the frames per second of the game, used to correct timings.
	*/
	void WeaponCard::update(float speedModifier) override;

	//! The draw method of the weapon card
	/*!
	This method will draw all the textures and buttons and the background.
	@param window The window on which everything has to be drawn.
	*/
	void WeaponCard::draw(sf::RenderWindow & window) const override;

	//! The getWeapon method of the weapon card
	/*!
	@return (a pointer to) The weapon this card represents
	*/
	Weapon * WeaponCard::getWeapon();

	//! The set weapon method of this class
	/*!
	@param weapon The weapon this card has to represent
	*/
	void WeaponCard::setWeapon(Weapon * weapon);

	//! The change weapon method of this weapon card
	/*!
	Switches this card with the card of the other weapon available for it's slot in the shop.
	*/
	void WeaponCard::changeWeapon();

	//! The deconstructor of the weapon card
	/*!
	The default deconstructor
	*/
	~WeaponCard();
private:
	sf::Sprite backgroundSprite, weaponSprite;
	sf::Texture backgroundTexture, weaponTexture;
	Weapon * weapon;
	sf::Text weaponInfo;
	float timeToUpdateInfo = 0;
	switchWeapon * switchButton;
	Upgrade * fireSpeedUpgrade, * damageUpgrade, * reloadSpeed;
};

