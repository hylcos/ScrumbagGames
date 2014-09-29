#include "../stdafx.h"
#include "Weapon.h"
#include "../TextureManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Weapon::Weapon()
{
}


void Weapon::fire(){
	std::cout << "Bang Bang /n";
}

void Weapon::update(float speedmodifer){

}

void Weapon::draw(sf::RenderWindow & window) const{
	//window.draw(bench);
}

Weapon::~Weapon()
{
}
