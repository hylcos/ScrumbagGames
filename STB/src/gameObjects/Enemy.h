#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
#include <SFML\Graphics.hpp>
class Enemy :
	public GameObject
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
	void Enemy::move(float speedModifier) override;
	void Enemy::draw(sf::RenderWindow & window) const override;
	Initializer average{ "Average" };

	~Enemy();
private:
	sf::Sprite sprite;
};

