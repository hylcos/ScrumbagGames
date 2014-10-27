#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

struct rectangle {
	sf::Vector2f vertex[4];
};

class Collision {
public:
	static bool Collision::collision(GameObject * s1, GameObject * s2);
private:
	static void  Collision::project(sf::Vector2f& axis, rectangle* _rectangle, float &min, float &max);
	static void  Collision::normalize(sf::Vector2f& vector);
	static float Collision::dot(sf::Vector2f& vector1, sf::Vector2f& vector2);
	static float Collision::distance(float minA, float maxA, float minB, float maxB);
};

