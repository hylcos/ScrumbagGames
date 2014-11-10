//! The play header file
/*!
This is the header file of the play butotn
*/
#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class Play :
	public Clickable
{
public:
	//! The constructor of the play button
	/*!
	The constructor loads the required texture and sets the origin of the button
	*/
	Play();

	//! The update method of the play button
	/*!
	The update method will update the position and the sprite for the play button
	@param speedModifier A value used to indicate the current speed of the game.
	*/
	void Play::update(float speedModifier) override;

	//! The draw method of the play button
	/*!
	This method will draw the button on the window
	@param window Which window the button has to be drawn on
	*/
	void Play::draw(sf::RenderWindow & window) const override;

	//! The click method of the button
	/*!
	This method specifies what happens when the user clicks on this button
	*/
	void Play::click() override;

	//! The get bounds method of the play button
	/*!
	@return The bounds of this particular button. Used to check if the user clicked on this button.
	*/
	sf::FloatRect Play::getBounds() override;

	//! The play button deconstructor
	/*!
	A defaul deconstructor
	*/
	~Play();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};