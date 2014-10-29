#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

struct rectangle {
	sf::Vector2f vertex[4];
};

class Collision {
private:

	struct Line{
		sf::Vector2f p1, p2;
	};
	static float Collision::distToSegment(Line line, sf::Vector2f point);
public:
	static bool Collision::collision(GameObject * square, GameObject * circle);
	static float Collision::dist2(sf::Vector2f p1, sf::Vector2f p2);
	static sf::Vector2f Collision::getClosestPoint(Line line, sf::Vector2f P);
	static sf::Vector2f Collision::getClosestPoint(GameObject * square, GameObject * circle);

};

