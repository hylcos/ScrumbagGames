#pragma once
#include "GameObject.h"
#include <SFML/Graphics.h>
class Circle :
	public GameObject
{
public:
	Circle();

	void Circle::draw(sf::RenderWindow & window) const;

	~Circle();
};

