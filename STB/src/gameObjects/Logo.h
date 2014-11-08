#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Logo :
	public GameObject
{
public:
	//! The Logo constructor
	/*!
	The constructor of Logo gets the needed texture from the texture manager.
	It also sets the origin of the sprite to the middle of the texture.
	*/
	Logo();

	//! Updates the sprite of the Logo
	/*!
	Updates the position of the Logo and counts time down for the splash screen
	@param speedModifier The speed of the game, so it is equal on every pc
	*/
	void Logo::update(float speedModifier) override;

	//! The Logo function of the Logo
	/*!
	Draws the current sprite of the Logo on the screen.
	@param window the screen on which the Logo should be drawn.
	*/
	void Logo::draw(sf::RenderWindow & window) const override;

	//! The deconstructor of a ParticleManager
	~Logo();
private:
	float time;
	sf::Texture texture;
	sf::Sprite logo;
};

