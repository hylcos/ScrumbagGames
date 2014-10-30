#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Particle :
	public GameObject
{
public:
	Particle(sf::Vector2f pos);
	void setColor(sf::Color);
	void setSpeed(float speed);
	void setDeceleration(float dec);
	void setDirection(float dir, float dev);
	void setRotation(float rot, float dev);
	void setSize(sf::Vector2f size);
	void setMinimumSpeed(float min);
	void Particle::update(float speedModifier) override;
	void Particle::move(float speedModifier) override;
	void Particle::draw(sf::RenderWindow & window) const override;
	~Particle();
private:
	float rotation;
	float direction;
	float particleSpeed;
	float deceleration;
	float minimumSpeed;
	sf::Vector2f prevPosition{ 0, 0 };
	sf::RectangleShape particle;
};

