#pragma once
#include "Animation.h"
#include "SFML\Graphics.hpp"
#include "ParticleEmitter.h"
#include "Weapon.h"
#include "Gun.h"

#include "Collision.h"
class Player : public Animation, ParticleEmitter
{
	struct hitbox
	{
		sf::VertexArray vertex;
	};
private:

	sf::Sprite curSprite;
	float rotation = 0.0;
	float doubleSpeedTimer,invincibleTimer;
	int curWeapon = 0;
	bool invincible;
	Weapon * selectedWeapons[3];
	bool isOnTable = false;
	int hp = 100;
	int speed = 1;
	int framesTillNextParticle = 0;
	int walkSound = 0;
	float toNextWalkSound = 0;
public:
	sf::Texture tex1, tex2, tex3;
	Player();
	~Player();
	void Player::move(float speedModifier) override;
	void Player::update(float speedModifier) override;
	void Player::draw(sf::RenderWindow & window) const override;
	void Player::setRotation(float rotation) override;
	void Player::reduceHP(int damage);
	void Player::setWeapons(Weapon * weapon1, Weapon * weapon2, Weapon * weapon3);
	Weapon * Player::getSelectedWeapon();
	int Player::getHp();
	sf::Vector2u Player::getSize() override;
	Weapon * Player::getWeapons(int value);
	float Player::getAmmo();
	void Player::doubleSpeed();
	void Player::fullHealth();
};

