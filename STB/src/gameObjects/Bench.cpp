#include "../stdafx.h"
#include "Bench.h"
#include "GameObject.h"
#include "../TextureManager.h"
Bench::Bench()
{
	pic = TextureManager::getInstance().getTexture("/Sprites/Bench.png");
	bench.setOrigin(63, 12);
	bench.setTexture(*pic);
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
