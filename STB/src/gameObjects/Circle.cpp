#include "../stdafx.h"
#include "Circle.h"


Circle::Circle(LevelController & levelController) : GameObject(levelController){

}

void Circle::draw(sf::RenderWindow & window) const{
	sf::CircleShape circle{ 5 };
	circle.setFillColor(sf::Color::Red);
	window.draw(circle);
}

Circle::~Circle()
{
}
