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
	\param window the screen on which the Trashcan should be drawn.
	*/
	void Trashcan::draw(sf::RenderWindow & window) const override;

	//! setRotation sets the rotation of the Trashcan texture
	/*!
	\param rotate The amount with which the Trashcan texture should be rotated.
	*/
	void Trashcan::setRotation(float rotate) override;

	//! Updates the texture of the Trashcan
	/*!
	Updates the position of the Trashcan.
	\param speedModifier isn't really used but is here because of the override.
	*/
	void Trashcan::update(float speedModifier) override;

	sf::FloatRect Trashcan::getBounds() override;

	sf::Transform Trashcan::getTransform() override;

	sf::Vector2u Trashcan::getSize() override;
private:
	//! The rotate amount of the texture.
	/*
	Indicates how much the texture should be rotated before it is drawn on the screen.
	*/
	float rotate;

	//! The texture used for the Trashcan.
	/*!
	The pointer to the texture of the Trashcan.
	*/
	sf::Texture * pic;

	//! The sprite of the Trashcan.
	/*!
	The sprite used to drawn the Trashcan on the screen.
	*/
	sf::Sprite trashcan;
};

