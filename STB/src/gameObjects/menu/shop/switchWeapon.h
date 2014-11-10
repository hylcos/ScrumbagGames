//! The switch weapon header file
/*!
This is the header file of the switch weapon button class
*/
#pragma once
#include "../../Clickable.h"
class switchWeapon : public Clickable
{
public:
	//! The constructor of the switch weapon class
	/*!
	The constructor will get the texture of the button.
	*/
	switchWeapon();

	//! The update method of the switch weapon class
	/*!
	This method will correct the position of this button, and call the update of the clickable class.
	@param speedModifier a value in our game used to indicate the gamespeed, based on the frames per second
	*/
	void switchWeapon::update(float speedModifier) override;

	//! The draw method of the switch weapon class
	/*!
	This method will draw the texture on the screen
	@param window The window it has to be drawn on
	*/
	void switchWeapon::draw(sf::RenderWindow & window) const override;

	//! the click method of the switch weapon class
	/*!
	This method will specify what should happen if this button is pressed.
	*/
	void switchWeapon::click() override;

	//! The is clicked method of the switch weapon class
	/*!
	@return a boolean representing the state of this button
	*/
	bool switchWeapon::isClicked();

	//! the get bounds method of the switch weapon button
	/*!
	@return the bounds of this button, used to check if the player has clicked on this button
	*/
	sf::FloatRect switchWeapon::getBounds() override;

	//! The deconstructor of the switch weapon class
	/*!
	The default deconstructor
	*/
	~switchWeapon();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	bool clicked = false;
};

