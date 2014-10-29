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
	void setSize(float size);
	void Particle::update(float speedModifier) override;
	void Particle::move(float speedModifier) override;
	void Particle::draw(sf::RenderWindow & window) const override;
	~Particle();
private:
	float rotation;
	float particleSpeed;
	float deceleration = 0.15f;
	sf::Vector2f prevPosition{ 0, 0 };
	sf::RectangleShape particle;
};

