#include "../stdafx.h"
#include "Weapon.h"
#include "../TextureManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gun.h"
Weapon::Weapon():
GameObject{weapon}
{
}


void Weapon::fire(){
}

void Weapon::update(float speedmodifer){
	
}

void Weapon::draw(sf::RenderWindow & window) const{

}

void Weapon::reload(){

}

float Weapon::getAmmo(){
	return 0;
}

std::string Weapon::getAmmoString(){
	return "Melee";
}

Weapon::~Weapon()
{
}
