#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
class Circle :
	public GameObject
{
public:
	Circle(LevelController & levelController) : GameObject(levelController){};

	void Circle::draw(sf::RenderWindow & window) const override;

	~Circle();
};

