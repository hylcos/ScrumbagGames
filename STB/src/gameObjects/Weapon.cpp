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
void Weapon::setAmmo(int amount){

}
bool Weapon::getIsReloading(){
	return false;
}
std::string Weapon::getAmmoString(){
	return "Melee";
}
int Weapon::getDamageLevel(){
	return 0;
}
void Weapon::upgradeDamage(){

}
void Weapon::doubleDamage(){

}
int Weapon::getFirerateLevel(){
	return 0;
}
void Weapon::upgradeFireRate(){

}

int Weapon::getReloadSpeedLevel(){
	return 0;
}
void Weapon::upgradeReloadSpeed(){

}

std::string Weapon::getName(){
	return " ";
}

std::string Weapon::getInfo(){
	return std::string("Hoi");
}
void Weapon::reset(){

}
void Weapon::resetAmmo(){

}
Weapon::~Weapon()
{
}
