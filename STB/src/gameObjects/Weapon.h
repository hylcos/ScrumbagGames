#pragma once

#include "GameObject.h"
class Weapon : public GameObject
{
public:
	Weapon();
	virtual void Weapon::fire();
	void Weapon::update(float speedModifier) override;
	virtual void Weapon::draw(sf::RenderWindow & window) const override;
	virtual void Weapon::reload();
	virtual float Weapon::getAmmo();
	void setMultipler();
	~Weapon();
	int multipler = 1;
};

