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
	static float Collision::dist2(sf::Vector2f p1, sf::Vector2f p2);
	static sf::Vector2f Collision::getClosestPoint(Line line, sf::Vector2f P);
	static sf::Vector2f Collision::getClosestPoint(GameObject * square, GameObject * circle);
public:
	//! collision method of Collision
	/*!
	This function gets to parameters and compares there globalBounds. Checks if they're intersecting
	@param circle first object
	@param square second Object
	@return true = intresect , false = aren't intersecting
	*/
	static bool Collision::collision(GameObject * circle, GameObject * square);
	

};

