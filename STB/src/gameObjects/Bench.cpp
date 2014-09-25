#include "../stdafx.h"
#include "Bench.h"
#include "GameObject.h"
#include "../TextureManager.h"
Bench::Bench()
{
	pic = TextureManager::getTexture("Bench.png");
	bench.setTexture(*pic);
}

void Bench::update(float speedmodifer){
	bench.setPosition(position);
}

void Bench::draw(sf::RenderWindow & window) const{
	window.draw(bench);
}
