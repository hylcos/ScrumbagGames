#pragma once
#include "Animation.h"
#include "../TextureManager.h"
#include <SFML\Graphics.hpp>
class Enemy :
	public Animation
{
private:
	class Initializer{
	public:
		Initializer(std::string name, float movementSpeed, int hp, bool melee, int damage, float attackSpeed);
		std::string getName();
		float getMovementSpeed();
		int getHP();
		bool isMelee();
		int getDamage();
		float getAttackSpeed();
	private:
		std::string name;
		float movementSpeed;
		int hp;
		bool melee;
		int damage;
		float attackSpeed;
	};
public:
	Enemy();
	Enemy(Initializer initializer);

	void Enemy::update(float speedModifier) override;
	void Enemy::draw(sf::RenderWindow & window) const override;
	void Enemy::move(float speedModifier) override;
	Initializer average{ "Average", 0.9f, 100, true, 20, 1 };

	~Enemy();
private:
	float hitCooldown;
	Initializer & type = average;
	sf::Sprite curSprite;
};

