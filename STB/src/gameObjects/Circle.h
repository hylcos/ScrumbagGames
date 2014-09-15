#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
class Circle :
	public GameObject
{
public:
	Circle();

	void Circle::draw(sf::RenderWindow & window) const override;

	~Circle();
};

