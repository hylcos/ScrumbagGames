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
		Initializer(std::string name);
		std::string getName();
	private:
		std::string name;
	};
public:
	Enemy();
	Enemy(Initializer initializer);

	void Enemy::update(float speedModifier) override;
	void Enemy::draw(sf::RenderWindow & window) const override;
	Initializer average{ "Average" };

	~Enemy();
private:
	sf::Sprite curSprite;
};

