//! The tutorial screen header file
/*!
This is the header file of the tutorial screen
*/
#pragma once
#include "../GameObject.h"
class TutorialScreen : public GameObject
{
public:
	//! The constructor of the tutorial screen
	/*!
	This method will load in the storyline and the controls of our game.
	When the player is in the tutorial screen he will be able to read all of this
	*/
	TutorialScreen();

	//! The update method of the tutorial screen
	/*!
	Only sets the positions off all the items in this screen
	@param speedModifier A value representing the current speed of the game, based on the frames per second.
	*/
	void TutorialScreen::update(float speedModifier) override;

	//! The draw method of the tutorial screen
	/*!
	This method will draw all the text on the screen
	@param window The screen on which the text has to be drawn
	*/
	void TutorialScreen::draw(sf::RenderWindow & window) const override;

	//! The deconstructor of the tutorial screen
	/*!
	The defaul deconstructor
	*/
	~TutorialScreen();

private :
	sf::Text mainText;
	sf::Text header;
	sf::Text story;
};

