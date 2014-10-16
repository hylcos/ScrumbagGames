//! The Bench header file
/*!
This is the header file of the bench class.
*/
#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Bench : public GameObject
{
public:
	//! The Bench constructor
	/*!
	The constructor of bench gets the needed texture from the texture manager.
	It also sets the origin of the sprite to the middle of the texture.
	*/
	Bench::Bench();

	//! The Draw function of the Bench
	/*!
	Draws the current sprite of the bench on the screen.
	\param window the screen on which the bench should be drawn.
	*/
	void Bench::draw(sf::RenderWindow & window) const override;

	//! setRotation sets the rotation of the Bench texture
	/*!
	\param rotate The amount with which the Bench texture should be rotated.
	*/
	void Bench::setRotation(float rotate) override;

	//! Updates the texture of the Bench
	/*!
	Updates the position of the bench.
	\param speedModifier isn't really used but is here because of the override.
	*/
	void Bench::update(float speedModifier) override;

	sf::FloatRect Bench::getBounds() override;
private:
	//! The rotate amount of the texture.
	/*
	Indicates how much the texture should be rotated before it is drawn on the screen.
	*/
	float rotate;

	//! The texture used for the Bench.
	/*!
	The pointer to the texture of the bench.
	*/
	sf::Texture * pic;

	//! The sprite of the Bench.
	/*!
	The sprite used to drawn the bench on the screen.
	*/
	sf::Sprite bench;
};

