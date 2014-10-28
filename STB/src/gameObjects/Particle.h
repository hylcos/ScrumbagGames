#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Particle :
	public GameObject
{
public:
	Particle(sf::Vector2f pos);
	void Particle::update(float speedModifier) override;
	void Particle::move(float speedModifier) override;
	void Particle::draw(sf::RenderWindow & window) const override;
	~Particle();
private:
	float rotation;
	float particleSpeed;
	sf::Vector2f prevPosition;
	sf::RectangleShape particle;
};

