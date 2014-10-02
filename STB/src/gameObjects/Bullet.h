#pragma once
#include "../stdafx.h"
#include "GameObject.h"
#include "../TextureManager.h"
#include <iostream>

class Bullet : public GameObject
{
public:
	Bullet(std::string imagename, float rotation, short bulletSpeed, int damage,sf::Vector2f position);
	void Bullet::update(float speedmodifer) override;
	void Bullet::move(float speedmodifier) override;
	void Bullet::draw(sf::RenderWindow & window) const override;
	sf::FloatRect Bullet::getBounds() override;
	~Bullet();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	sf::Vector2f prevPosition;
	sf::VertexArray collision;
	int damage;
	float rotation;
	short bulletSpeed;
};

