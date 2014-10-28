#include <math.h>
#include "Collision.h"
#include <iostream>

/*void Collision::normalize(sf::Vector2f& vector) {
	const float length = sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length == 0)
	return;
	vector.x = vector.x / length;
	vector.y = vector.y / length;
	}

	float Collision::dot(sf::Vector2f& vector1, sf::Vector2f& vector2)
	{
	return vector1.x*vector2.x + vector1.y*vector2.y;
	}

	float Collision::distance(float minA, float maxA, float minB, float maxB) // Positive return = no hit
	{
	if (minB > maxA) return minB - maxA;
	else return minA - maxB;
	}




	void  Collision::project(sf::Vector2f& axis, rectangle* _rectangle, float &min, float &max)
	{
	float _dot = dot(axis, _rectangle->vertex[0]);

	min = _dot;
	max = _dot;

	for (short i = 1; i<4; i++)
	{
	_dot = dot(_rectangle->vertex[i], axis);

	if (_dot<min)
	min = _dot;
	else if (_dot>max)
	max = _dot;
	}
	}*/

float Collision::dist2(sf::Vector2f p1, sf::Vector2f p2){
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

float Collision::distToSegment(Line line, sf::Vector2f point){
	float lineLenght = dist2(line.p1, line.p2);
	if (lineLenght == 0) return dist2(line.p1, point);
	float t = ((point.x - line.p1.x) * (line.p2.x - line.p1.x) + (point.y - line.p1.y) * (line.p2.y - line.p1.y)) / lineLenght;
	if (t < 0) return dist2(point, line.p1);
	if (t > 1) return dist2(point, line.p2);
	return sqrt(dist2(point, sf::Vector2f{ line.p1.x + t * (line.p2.x - line.p1.x),
		line.p1.y + t * (line.p2.y - line.p1.y) }));
}

bool Collision::collision(GameObject * circle, GameObject * square)
{
	sf::FloatRect rect = square->getBounds();
	float maxDist = circle->getSize().x / 2.0f;
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

	/*rectangle one;
	rectangle two;

	sf::Transform transform = s1->getTransform();
	sf::FloatRect rect = s1->getBounds();

	one.vertex[0] = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
	one.vertex[1] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	one.vertex[2] = transform.transformPoint(sf::Vector2f(rect.left + rect.width,rect.top + rect.height));
	one.vertex[3] = transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height));

	transform = s2->getTransform();
	rect = s2->getBounds();

	two.vertex[0] = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
	two.vertex[1] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	two.vertex[2] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height));
	two.vertex[3] = transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height));

	sf::Vector2f axis;
	float minA;
	float minB;
	float maxA;
	float maxB;


	// Test one
	axis.x = one.vertex[1].x - one.vertex[0].x;
	axis.y = one.vertex[1].y - one.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB)>0.f)
	return false;


	// Test two
	axis.x = one.vertex[3].x - one.vertex[0].x;
	axis.y = one.vertex[3].y - one.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB)>0.f)
	return false;


	// Test three
	axis.x = two.vertex[1].x - two.vertex[0].x;
	axis.y = two.vertex[1].y - two.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB)>0.f)
	return false;


	// Test four
	axis.x = two.vertex[3].x - two.vertex[0].x;
	axis.y = two.vertex[3].y - two.vertex[0].y;
	normalize(axis);

	project(axis, &one, minA, maxA);
	project(axis, &two, minB, maxB);

	if (distance(minA, maxA, minB, maxB)>0.f)
	return false;

	return true;
	*/
}
