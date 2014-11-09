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
	@param window the screen on which the bench should be drawn.
	*/
	void Bench::draw(sf::RenderWindow & window) const override;

	//! setRotation sets the rotation of the Bench texture
	/*!
	@param rotate The amount with which the Bench texture should be rotated.
	*/
	void Bench::setRotation(float rotate) override;

	//! Updates the texture of the Bench
	/*!
	Updates the position of the bench.
	@param speedModifier isn't really used but is here because of the override.
	*/
	void Bench::update(float speedModifier) override;

	//! gets the bounds of the Bench
	/*!
	Gets the bounds of the sprite and returns this.
	@return the bounds of the sprite so they can be compared with
	the bounds of the player and see if they intersect
	*/
	sf::FloatRect Bench::getBounds() override;

	//! gets the Transformation of the Bench
	/*!
	Gets the Transformation of the sprite and returns this.
	@return the Transformation of the sprite so it can be
	calculated into the real bounds of the object
	*/
	sf::Transform Bench::getTransform() override;

	//! Gives the size of the bench
	/*!
	@return a Vector that is the size of the bench 
	*/
	sf::Vector2u Bench::getSize() override;
private:
	float rotate;
	sf::Texture * pic;
	sf::Sprite bench;
};

