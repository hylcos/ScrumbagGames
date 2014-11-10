#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
#include <SFML\Graphics.hpp>
class Table :
	public GameObject
{
public:
	//! The Table constructor
	/*!
	The constructor of Table gets the needed texture from the texture manager.
	It also sets the origin of the sprite to the middle of the texture.
	*/
	Table();

	//! The Draw function of the Table
	/*!
	Draws the current sprite of the Table on the screen.
	@param window the screen on which the Table should be drawn.
	*/
	void Table::draw(sf::RenderWindow & window) const override;

	//! setRotation sets the rotation of the Table texture
	/*!
	@param rotate The amount with which the Table texture should be rotated.
	*/
	void Table::setRotation(float rotate) override;

	//! Updates the sprite of the Table
	/*!
	Updates the position of the Table.
	@param speedModifier isn't really used but is here because of the override.
	*/
	void Table::update(float speedModifier) override;

	//! gets the bounds of the Table
	/*!
	Gets the bounds of the sprite and returns this.
	@return the bounds of the sprite so they can be compared with
	the bounds of the player and see if they intersect
	*/
	sf::FloatRect Table::getBounds() override;

	//! gets the Transformation of the Table
	/*!
	Gets the Transformation of the sprite and returns this.
	@return the Transformation of the sprite so it can be
	calculated into the real bounds of the object
	*/
	sf::Transform Table::getTransform() override;

	~Table();

private:
	sf::Uint8 state;
	sf::Texture * tex;
	sf::Sprite table;
	};
