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
	virtual std::string Weapon::getAmmoString();
	virtual std::string Weapon::getName();
	virtual void Weapon::setAmmo(int amount);
	void setMultipler();
	~Weapon();
	int multipler = 1;
};

