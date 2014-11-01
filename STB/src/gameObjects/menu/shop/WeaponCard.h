#pragma once
#include "../../Weapon.h"
class WeaponCard : public GameObject
{
public:
	WeaponCard();

	WeaponCard::WeaponCard(Weapon * weapon);
	void WeaponCard::update(float speedModifier) override;
	void WeaponCard::draw(sf::RenderWindow & window) const override;


	~WeaponCard();
private:
	sf::Sprite sprite;
	sf::Texture tex;
	Weapon * weapon;
};

