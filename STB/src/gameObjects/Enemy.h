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
		Initializer(std::string name, float movementSpeed);
		std::string getName();
		float getMovementSpeed();
	private:
		std::string name;
		float movementSpeed;
	};
public:
	Enemy();
	Enemy(Initializer initializer);

	void Enemy::update(float speedModifier) override;
	void Enemy::draw(sf::RenderWindow & window) const override;
	void Enemy::move(float speedModifier) override;
	Initializer average{ "Average", 0.8f };

	~Enemy();
private:
	float movementSpeed;
	sf::Sprite curSprite;
};

