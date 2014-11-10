//! The shop header file
/*!
This is the header file of the shop button class
*/
#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class Shop :
	public Clickable
{
public:

	//! The constructor of the shop button
	/*!
	The constructor will load in the textures used by this button and set its origin.
	*/
	Shop();

	//! The update method of the shop
	/*!
	The update method will set the position of the shop button
	@param speedModifier A value representing the speed of the game, based on the frames per second
	*/
	void Shop::update(float speedModifier) override;

	//! The draw method of the shop button class
	/*!
	This method will draw the button on the screen
	@param window The window on which the button has to be drawn
	*/
	void Shop::draw(sf::RenderWindow & window) const override;

	//! The click method of the shop button class
	/*!
	This method specifies what happens when the user clicks on the shop button.
	*/
	void Shop::click() override;

	//! The get bounds method of the shop button class
	/*!
	@return The bounds of this particular button. Used to check if the users click was on this button.
	*/
	sf::FloatRect Shop::getBounds() override;

	//! The deconstructor of the shop button
	/*!
	A default deconstructor
	*/
	~Shop();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

