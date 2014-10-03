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
	Enemy(Initializer  initializer);

	void Enemy::reduceHP(int damage);
	void Enemy::update(float speedModifier) override;
	void Enemy::draw(sf::RenderWindow & window) const override;
	void Enemy::move(float speedModifier) override;
	void Enemy::setType(Initializer initializer);

	Initializer average{ "Average", 0.9f, 100, true, 20, 60 };
	Initializer fat{ "Fat", 0.7f, 300, true, 20, 60 };
	Initializer cheerleader{ "Cheerleader", 1.3f, 50, true, 20, 100 };
	Initializer horde{ "Horde", 0.7f, 70, true, 20, 70 };
	Initializer macho{ "Macho", 0.8f, 100, true, 40, 30 };

	Initializer dunken{ "Boss Dunken", 0.9f, 1500, true, 20, 60 };
	
	~Enemy();
private:
	float hitCooldown = 0;
	int dmg = 0;
	Initializer & type = average;
	sf::Sprite curSprite;
};

