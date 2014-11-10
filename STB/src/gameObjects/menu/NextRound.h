#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class NextRound :
	public Clickable
{
public:
	//! The constructor of the NextRound button
	/*!
	The constructor loads the required texture and sets the origin of the button
	*/
	NextRound();

	//! The update method of the NextRound button
	/*!
	The update method will update the position and the sprite for the NextRound button
	@param speedModifier A value used to indicate the current speed of the game.
	*/
	void NextRound::update(float speedModifier) override;

	//! The draw method of the NextRound button
	/*!
	This method will draw the button on the window
	@param window Which window the button has to be drawn on
	*/
	void NextRound::draw(sf::RenderWindow & window) const override;
	//! The click method of the button
	/*!
	When the button is clicked, this method is called and the Next Round is loaded
	*/
	void NextRound::click() override;
	//! The get bounds method of the NextRound button
	/*!
	@return The bounds of the NextRound button. Used to check if the user clicked on this button.
	*/
	sf::FloatRect NextRound::getBounds() override;

	//! The NextRound button deconstructor
	/*!
	A default deconstructor
	*/
	~NextRound();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

