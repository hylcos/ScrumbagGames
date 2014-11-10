#pragma once
#include "..\Clickable.h"
class MainMenu :
	public Clickable
{
public:
	//! The constructor of the MainMenu button
	/*!
	The constructor loads the required texture and sets the origin of the button
	*/
	MainMenu();	

	//! The update method of the MainMenu button
	/*!
	The update method will update the position and the sprite for the MainMenu button
	@param speedModifier A value used to indicate the current speed of the game.
	*/
	void MainMenu::update(float speedModifier) override;

	//! The draw method of the MainMenu button
	/*!
	This method will draw the button on the window
	@param window Which window the button has to be drawn on
	*/
	void MainMenu::draw(sf::RenderWindow & window) const override;

	//! The click method of the button
	/*!
	When the button is clicked, this method is called the Game whill go back to the main Menu
	*/
	void MainMenu::click() override;

	//! The get bounds method of the MainMenu button
	/*!
	@return The bounds of the MainMenu button. Used to check if the user clicked on this button.
	*/
	sf::FloatRect MainMenu::getBounds() override;

	//! The MainMenu button deconstructor
	/*!
	A default deconstructor
	*/
	~MainMenu();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

