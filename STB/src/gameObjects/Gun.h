#pragma once
#include "../stdafx.h"
#include "Bullet.h"
#include "Weapon.h"
#include "../TextureManager.h"
#include <iostream>
class Gun : public Weapon
{
public:
	Gun::Gun(std::string name,int damage, float reloadSpeed,int magazineSize,int range, short bulletSpeed);
	void Gun::fire() override;
	void Gun::update(float speedModifier) override;
	void Gun::draw(sf::RenderWindow & window) const override;
	void Gun::setRotation(float rotation) override;
	Gun::~Gun();
private:
	sf::Sprite sprite;
	sf::Texture tex;
	std::string name;

	int damage, magazineSize, range;
	short bulletSpeed;
	float reloadSpeed,rotation;
};

