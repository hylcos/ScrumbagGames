#include "../stdafx.h"
#include "Circle.h"
#include "GameObject.h"

Circle::Circle()
{
}

void Circle::draw(sf::RenderWindow & window) const{
	sf::CircleShape circle{ 5 };
	circle.setFillColor(sf::Color::Red);
	window.draw(circle);
}

Circle::~Circle()
{
}
