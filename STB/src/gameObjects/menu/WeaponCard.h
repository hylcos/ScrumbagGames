#pragma once
#include "../Weapon.h"
class WeaponCard : public GameObject
{
public:
	WeaponCard();

	WeaponCard::WeaponCard(Weapon * weapon);

	~WeaponCard();
};

