#include "../stdafx.h"
#include "Bench.h"
#include "GameObject.h"

Bench::Bench()
{
	pic.loadFromFile("Resources/Images/Bench.png");
	bench.setTexture(pic);
}

void Bench::update(float speedmodifer){
	bench.setPosition(position);
}
void Bench::setRotation(float rotate){
	bench.rotate(rotate);
}

void Bench::draw(sf::RenderWindow & window) const{
	window.draw(bench);
}
