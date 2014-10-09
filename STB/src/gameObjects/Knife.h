#pragma once
#include "../stdafx.h"
#include "Weapon.h"
#include "../TextureManager.h"
#include <iostream>

class Knife : public Weapon 
{
public:
	Knife::Knife(std::string name, int damage, short attackSpeed, int range);
	void Knife::fire();
	void Knife::update(float speedModifier) override;
	void Knife::draw(sf::RenderWindow & window) const override;
	void Knife::setRotation(float rotation);
private:
	sf::Sprite sprite, melee;
	sf::Texture tex, texmelee;
	std::string name;
	bool drawMelee;

	int damage, range;
	short attackSpeed;
	float hitCooldown = 0, rotation;
	
};

