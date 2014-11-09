#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Particle :
	public GameObject
{
public:
	//! The Particle constructor
	/*!
	@param pos The begin Position where the partical has to be placed
	*/
	Particle(sf::Vector2f pos);

	//! The setColor method of Partical
	/*!
	@param color : the new color of the Partical
	*/
	void setColor(sf::Color color);

	//! The setSpeed method of Partical
	/*!
	@param speed : the new speed of the Partical
	*/
	void setSpeed(float speed);

	//! The setDeceleration method of Partical
	/*!
	@param dec : the new Deceleration of the Partical
	*/
	void setDeceleration(float dec);

	//! The setDirection method of Partical
	/*!
	@param dir : the new Direction of the Partical
	@param dev : the new Deviaton of the Direction of the Partical
	*/
	void setDirection(float dir, float dev);

	//! The setRotation method of Partical
	/*!
	@param rot : the new Rotation of the Partical
	@param dev : the new Deviaton of the Rotation of the Partical
	*/
	void setRotation(float rot, float dev);

	//! The setSize method of Partical
	/*!
	@param size : The new size of the Particals
	*/
	void setSize(float size);

	//! The setMinimumSpeed method of Partical
	/*!
	@param min : the minimunSpeed of the Particals
	*/
	void setMinimumSpeed(float min);
	
	//! The setGore method of Partical
	/*!
	@param g : true if there can be blood in screen,
	false if there can't be blood on the screen
	*/
	void setGore(bool g);

	//! The Update method of Partical
	/*!
	retracts some speed of the Partical and if they come below there
	minimum speed they will get destroyed
	@param speedModifier : The Speed of The Game
	*/
	void Particle::update(float speedModifier) override;

	//! The move method of Partical
	/*!
	changes the position on the basis of the ParticalSpeed
	@param speedModifier : The Speed of The Game
	*/
	void Particle::move(float speedModifier) override;

	//! The draw Method of Partical
	/*!
	@param window the screen on which the Partical has to been draw on.
	*/
	void Particle::draw(sf::RenderWindow & window) const override;

	//! The getGore Method of Partical
	/*!
	returns the value of isGore so they players who doesn't wan't to see blood doens't
	@return the value of isGore
	*/
	bool getGore();

	//! The deconstructor of a Particle
	/*!
	*/
	~Particle();
private:
	float rotation;
	float direction;
	float particleSpeed;
	float deceleration;
	float minimumSpeed;
	bool isGore;
	sf::Vector2f prevPosition{ 0, 0 };
	sf::CircleShape particle;
};

