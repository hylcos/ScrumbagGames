#pragma once
#include "../stdafx.h"
#include "Gun.h"
#include "SFML\Graphics.hpp"
#include "GameObject.h"
#include "../LevelController.h"
class Bullet : public GameObject
{
public:
	Bullet(std::string imagename, float rotation, short bulletSpeed, int damage,sf::Vector2f position);
	void Bullet::update(float speedmodifer) override;
	void Bullet::draw(sf::RenderWindow & window) const override;
	sf::FloatRect Bullet::getLine();
	~Bullet();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	sf::Vector2f posOld, posNew;
	sf::VertexArray collision;
	int damage;
	float rotation;
	short bulletSpeed;
};

