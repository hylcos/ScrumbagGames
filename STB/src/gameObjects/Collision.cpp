#include <math.h>
#include "Collision.h"
#include <iostream>

float Collision::dist2(sf::Vector2f p1, sf::Vector2f p2){
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

sf::Vector2f Collision::getClosestPoint(Line line, sf::Vector2f P){

	sf::Vector2f distFromP1ToPlayer = { P.x - line.p1.x, P.y - line.p1.y };
	sf::Vector2f lineLength = { line.p2.x - line.p1.x, line.p2.y - line.p1.y };

	float atb2 = pow(lineLength.x, 2.0f) + pow(lineLength.y, 2.0f);
	//Basically finding the squared magnitude of a_to_b

	float atp_dot_atb = distFromP1ToPlayer.x * lineLength.x + distFromP1ToPlayer.y * lineLength.y;
	//The dot product of a_to_p and a_to_b

	float t = atp_dot_atb / atb2;
	//The normalized "distance" from a to your closest point

	if (t < 0) return line.p1;
	if (t > 1) return line.p2;

	return sf::Vector2f{ line.p1.x + lineLength.x * t, line.p1.y + lineLength.y * t };
	//Add the distance to A, moving towards B

}

sf::Vector2f Collision::getClosestPoint(GameObject * square, GameObject * circle){
	float closestDistance = 128.0f*128.0f;
	sf::Vector2f closestPoint;
	sf::FloatRect rect = square->getBounds();
	sf::Vector2f circleOrigin = circle->getPosition();

	sf::Transform transform = square->getTransform();

	rectangle one;
	one.vertex[0] = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
	one.vertex[1] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	one.vertex[2] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height));
	one.vertex[3] = transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height));

	Line middleLine{ transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height / 2)), transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height / 2)), };
	Line lines[] = { Line{ one.vertex[0], one.vertex[1] }, Line{ one.vertex[2], one.vertex[1] }, Line{ one.vertex[2], one.vertex[3] }, Line{ one.vertex[0], one.vertex[3] }, middleLine };

	for (Line & line : lines){
		sf::Vector2f point = getClosestPoint(line, circleOrigin);
		if (dist2(point, circleOrigin) < closestDistance){
			closestPoint = point;
			closestDistance = dist2(point, circleOrigin);
		}
	}
	return closestPoint;
}

float Collision::distToSegment(Line line, sf::Vector2f point){
	sf::Vector2f closestPoint = getClosestPoint(line, point);
	return sqrt(dist2(point, closestPoint));
}

bool Collision::collision(GameObject * circle, GameObject * square)
{
	sf::FloatRect rect = square->getBounds();
	float maxDist = std::max(circle->getSize().x,circle->getSize().y) / 2.0f;
	sf::Vector2f circleOrigin = circle->getPosition();

	sf::Transform transform = square->getTransform();

	rectangle one;
	one.vertex[0] = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
	one.vertex[1] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	one.vertex[2] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height));
	one.vertex[3] = transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height));

	Line middleLine{ transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height / 2)), transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height / 2)), };
	Line lines[] = { Line{ one.vertex[0], one.vertex[1] }, Line{ one.vertex[2], one.vertex[1] }, Line{ one.vertex[2], one.vertex[3] }, Line{ one.vertex[0], one.vertex[3] }, middleLine };

	for (Line & line : lines){
		if (distToSegment(line, circleOrigin) < maxDist){
			return true;
		}
	}
	return false;
}
