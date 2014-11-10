//! The header file of the options button
/*!
This is the header file of the options button in the menus.
*/

#pragma once
#include "..\Clickable.h"
class Options :
	public Clickable
{
public:

	//! The constructor of the options button
	/*!
	The construcotr will load in the texture and set the origin of the button
	*/
	Options();

	//! The update method of the options button
	/*!
	This method will update the position and sprite of the options butotn
	@param speedModifier A value used in our game to indicate its current speed.
	*/
	void Options::update(float speedModifier) override;

	//! The draw method of the options button
	/*!
	This method will draw the button in the window
	@param window Which window the button has to be drawn in
	*/
	void Options::draw(sf::RenderWindow & window) const override;

	//! The click method of the options button
	/*!
	This method specifies what should happen when the user clicks on this button.
	*/
	void Options::click() override;

	//! The get bounds method of the options button.
	/*!
	@return The bounds of this button. Used to check if the user has clicked on this button
	*/
	sf::FloatRect Options::getBounds() override;

	//! The options button deconstructor
	/*!
	A default deconstructor
	*/
	~Options();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

