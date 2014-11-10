//! The Trashcan header file
/*!
This is the header file of the Trashcan class.
*/
#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Trashcan : public GameObject
{
public:
	//! The Trashcan constructor
	/*!
	The constructor of Trashcan gets the needed texture from the texture manager.
	It also sets the origin of the sprite to the middle of the texture.
	*/
	Trashcan::Trashcan();

	//! The Draw function of the Trashcan
	/*!
	Draws the current sprite of the Trashcan on the screen.
	@param window the screen on which the Trashcan should be drawn.
	*/
	void Trashcan::draw(sf::RenderWindow & window) const override;

	//! setRotation sets the rotation of the Trashcan texture
	/*!
	@param rotate The amount with which the Trashcan texture should be rotated.
	*/
	void Trashcan::setRotation(float rotate) override;

	//! Updates the sprite of the Trashcan
	/*!
	Updates the position of the Trashcan.
	@param speedModifier isn't really used but is here because of the override.
	*/
	void Trashcan::update(float speedModifier) override;

	//! gets the bounds of the Trashcan
	/*!
	Gets the bounds of the sprite and returns this.
	@return the bounds of the sprite so it can be compared with
	the bounds of the player and see if they intersect
	*/
	sf::FloatRect Trashcan::getBounds() override;


private:

	float rotate;
	sf::Texture * pic;
	sf::Sprite trashcan;
};

