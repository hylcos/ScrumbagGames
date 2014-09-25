#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Bench : 
	public GameObject
{

public:
	void Bench::draw(sf::RenderWindow & window) const override;
	void Bench::setRotation(float rotate);
	Bench::Bench();
	void Bench::update(float speedModifier) override;

private:
	float rotate;
	sf::Texture pic;
	sf::Sprite bench;
};

