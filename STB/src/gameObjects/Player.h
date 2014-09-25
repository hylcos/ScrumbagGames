#pragma once
#include "Animation.h"
#include "SFML\Graphics.hpp"
class Player : public Animation
{

private:
	
	sf::Sprite curSprite;

public:
	sf::Texture tex1, tex2, tex3;
	Player();
	~Player();

	void Player::update(float speedModifier) override;
	void Player::draw(sf::RenderWindow & window) const override;
	
};

