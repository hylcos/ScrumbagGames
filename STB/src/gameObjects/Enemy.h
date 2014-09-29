#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
private:
	class Initializer{
	public:
		Initializer(std::string name);
	private:
		std::string name;
	};
public:
	Enemy(Initializer initializer);

	void Enemy::update(float speedModifier) override;
	void Enemy::move(float speedModifier) override;
	void Enemy::draw(sf::RenderWindow & window) const override;
	Initializer average{ "Average" };

	~Enemy();
};

