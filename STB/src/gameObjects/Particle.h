#pragma once
#include "C:\Users\Tim\Documents\GitHub\ScrumbagGames\STB\src\gameObjects\GameObject.h"

#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Particle :
	public GameObject
{
public:
	Particle(sf::Vector2f pos);
	~Particle();
};

