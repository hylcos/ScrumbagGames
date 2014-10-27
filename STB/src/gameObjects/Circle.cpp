#include "../stdafx.h"
#include "Circle.h"
#include "GameObject.h"

Circle::Circle()
{
	circle = sf::CircleShape{ circleSize };
	circle.setFillColor(circleColor);
}

void Circle::draw(sf::RenderWindow & window) const{
	window.draw(circle);
}

Circle::~Circle()
{
}
