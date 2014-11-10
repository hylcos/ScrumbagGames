//! The resume header file
/*!
The header file of the resume button class
*/
#pragma once
#include "..\Clickable.h"
class Resume :
	public Clickable
{
public:

	//! The contructor of the resume class
	/*!
	The constructor will load the texture of this button and set its origin
	*/
	Resume();

	//! The update method of the resume button
	/*!
	This method will update the position of the button
	@param speedModifier A value used to indicate the speed of the game.
	*/
	void Resume::update(float speedModifier) override;

	//! The draw method of the resum button
	/*!
	This method will draw the button on the screen
	@param window What screen the button has to be drawn on
	*/
	void Resume::draw(sf::RenderWindow & window) const override;

	//! The click method of the resume button
	/*!
	This method will specify what has to happen when this button gets clicked
	*/
	void Resume::click() override;

	//! The get bounds method of the resume button
	/*!
	@return The bounds of the resume button. Used to check if the users click was on this particular button
	*/
	sf::FloatRect Resume::getBounds() override;

	//! The deconstructor of the resume button
	/*!
	A defaul deconstructor
	*/
	~Resume();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

