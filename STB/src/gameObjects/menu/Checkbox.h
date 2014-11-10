//! The Checkbox header file
/*!
This is the header file of the checkbox class.
*/
#pragma once
#include "..\Clickable.h"
class Checkbox :
	public Clickable
{
public:
	//! The constructor of the checkbox class
	/*!
	Just a default constructor
	*/
	Checkbox();

	//! The initializer of the checkbox.
	/*!
	Loads the images used for the checkbox
	*/
	void Checkbox::init();

	//! The update method of the checkbox
	/*!
	Updates the sprite of the checkbox.
	@param speedModifier A modifier for the timings based on the amount of frames per second of the game.
	*/
	void Checkbox::update(float speedModifier) override;

	//! The draw method of the checkbox
	/*!
	Draws the checkbox with its correct sprite on the screen
	@param window The screen on which it should be drawn
	*/
	void Checkbox::draw(sf::RenderWindow & window) const override;

	//! The click method of the checkbox
	/*!
	Changes the state of the checkbox when its clicked
	*/
	void Checkbox::click() override;

	//! The get bounds method of the checkbox
	/*!
	@return The bounds of the checkbox.
	*/
	sf::FloatRect Checkbox::getBounds() override;

	//! The deconstructor of the checkbox
	/*!
	The default deconstructor
	*/
	~Checkbox();
protected:
	bool checked;
	virtual void Checkbox::toggle(bool checked);
	sf::Text text;
private:
	sf::Texture * texChecked, *texUnchecked;
	sf::Sprite sprite;
};

