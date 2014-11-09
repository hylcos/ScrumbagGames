//! The tutorial header file
/*
This is the header file of the tutorial class
*/
#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class Tutorial :
	public Clickable
{
public:
	//! the constructor of the tutorial butotn
	/*!
	This constructor will get the texture for the button, and set its origin
	*/
	Tutorial();

	//! The update method of the tutorail
	/*!
	The update method will only update the position of the button, and set its sprite.
	@param speedModifier A value that represents the speed of the game based on the frames per second.
	*/
	void Tutorial::update(float speedModifier) override;

	//! The draw method of the tutorial
	/*!
	The draw method will draw te button on the screen
	@param window The screen the button has to be drawn on.
	*/
	void Tutorial::draw(sf::RenderWindow & window) const override;

	//! The click method of the tutorial button
	/*!
	This method specifies what will happen when the tutorial button is clicked.
	*/
	void Tutorial::click() override;

	//! The get bounds method of the tutorial button
	/*!
	@return The bounds of the tutorial button, used to check if the player has clicked on this button.
	*/
	sf::FloatRect Tutorial::getBounds() override;

	//! The deconstructor of the tutorial button
	/*!
	The defaul deconstructor
	*/
	~Tutorial();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

