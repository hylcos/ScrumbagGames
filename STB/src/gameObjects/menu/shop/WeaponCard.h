#pragma once
#include "../../Weapon.h"
#include "Upgrade.h"
class WeaponCard : public GameObject
{
public:
	WeaponCard();

	WeaponCard::WeaponCard(Weapon * weapon);
	void WeaponCard::update(float speedModifier) override;
	void WeaponCard::draw(sf::RenderWindow & window) const override;
	Weapon * WeaponCard::getWeapon();
	void WeaponCard::setWeapon(Weapon * weapon);

	~WeaponCard();
private:
	sf::Sprite backgroundSprite, weaponSprite;
	sf::Texture backgroundTexture, weaponTexture;
	Weapon * weapon;
	sf::Text weaponInfo;
	Upgrade * fireSpeedUpgrade, * damageUpgrade;
};

