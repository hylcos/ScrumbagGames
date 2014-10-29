//! The Bullet header file
/*!
This is the header file of the bullet class.
*/
#pragma once
#include "../stdafx.h"
#include "GameObject.h"
#include "ParticleEmitter.h"
#include "../TextureManager.h"
#include <iostream>

class Bullet : public GameObject, ParticleEmitter
{
public:
	//! The constructor of the bullet
	/*!
	The constructor mainly sets all the attributes of the bullet.
	\param imagename The name the texture has in our directories.
	\param rotation The amount the bullet should be rotated (the direction from the player to the mouse pointer).
	\param bulletSpeed The speed of the bullet depending on what weapon the bullet is shot with.
	\param damage The damage the bullet deals when it hits a bully.
	\param postion Where the bullet is spawned on the screen.
	*/
	Bullet(std::string imagename, float rotation, short bulletSpeed, int damage,sf::Vector2f position);

	//! The update function of the bullet
	/*!
	Checks if the bullet touches an enemy,
	and if so, reduces the hp of the bully and deletes itself.
	\param speedmodifier Isn't really used but is here because of the override.
	*/
	void Bullet::update(float speedmodifer) override;
	
	//! The Move function of the bullet
	/*!
	This method calculates the new position of the bullet based on the previous position
	and the speed of the bullet. It also checks if the bullet is out of the screen, and
	if it is the bullet will be deleted.
	\param speedmodifier Isn't really used but is here because of the override.
	*/
	void Bullet::move(float speedmodifier) override;

	//! Draws the bullet
	/*!
	This method draws the sprite of the bullet on the screen.
	\param window The window the sprite should be drawn on.
	*/
	void Bullet::draw(sf::RenderWindow & window) const override;

	//! gives the bounds of the Bullet.
	/*!
	\return The bounds of the bullet based on the current position and rotation.
	*/
	sf::FloatRect Bullet::getBounds() override;

	//! The destructor of the Bullet class
	/*!
	Destroys the Bullet.
	*/
	~Bullet();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	sf::Vector2f prevPosition;
	sf::VertexArray collision;
	int damage;
	float rotation;
	short bulletSpeed;
};

