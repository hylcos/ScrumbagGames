#pragma once
#include "Animation.h"
#include "SFML\Graphics.hpp"
#include "Weapon.h"
#include "Gun.h"
class Player : public Animation
{

private:

	sf::Sprite curSprite;
	float toNext = 0.0;
	float rotation = 0.0;
	int curWeapon = 0;
	Weapon * selectedWeapons[3];

public:
	sf::Texture tex1, tex2, tex3;
	Player();
	~Player();
	void Player::move(float speedModifier) override;
	void Player::update(float speedModifier) override;
	void Player::draw(sf::RenderWindow & window) const override;
	void Player::setRotation(float rotation) override;
	void Player::setWeapons(Weapon * weapon1, Weapon * weapon2, Weapon * weapon3);
	Weapon * Player::getSelectedWeapon();

};

