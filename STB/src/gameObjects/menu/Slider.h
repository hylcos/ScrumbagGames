//! The slider header file
/*!
This is the header file of the slider class
*/
#pragma once
#include "..\Clickable.h"
class Slider :
	public Clickable
{
public:
	//! The constructor of the slider class
	/*!
	The slider will load the textures of both the slider bar and the slider itself
	*/
	Slider();

	//! The draw method of the slider class
	/*!
	The draw method will draw everything on the screen. This includes the bar and the slider at its curren position
	@param window The window everything has to be drawn on
	*/
	void Slider::draw(sf::RenderWindow & window) const override;

	//! The release method of the slider class
	/*!
	Specifies what should happen when the user releases the slider at a specific position
	*/
	void Slider::release() override;

	//! The press method of the slider class
	/*!
	Specifies what should happen when the user presses the slider
	*/
	void Slider::press() override;

	//! The update method of the slider class
	/*!
	Updates the position of the slider according to the mouse of the user, if this slider is selected
	@param speedModifier A value representing the speed of the game, based on the frames per second.
	*/
	void Slider::update(float speedModifier) override;

	//! the update value method of the slider class
	/*!
	@param value Updates the internal value to this given paramater
	*/
	virtual void Slider::updateValue(int value);

	//! The get bounds method of the slider class
	/*!
	@return The bounds of the slider
	*/
	sf::FloatRect Slider::getBounds() override;

	//! The deconstructor of the slider class
	/*!
	A default deconstructor
	*/
	~Slider();
protected:
	int value;
private:
	bool selected = false;
	sf::Sprite spriteScrollButton, spriteScrollBar;
};

