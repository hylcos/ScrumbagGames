#pragma once

#include "GameObject.h"
class Weapon : public GameObject
{
public:
	Weapon();
	 virtual void Weapon::fire();

	void Weapon::update(float speedModifier) override;
	void Weapon::draw(sf::RenderWindow & window) const override;

	~Weapon();
};

