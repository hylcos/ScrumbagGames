#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"
Player::Player():
Animation{}
{
	Animation::setTextures(*TextureManager::getTexture("Resources/Images/Sprites/Player-1.png"),*TextureManager::getTexture("Resources/Images/Sprites/Player-2.png"));
}

void Player::update(float speedModifier) {
	 
}
void Player::draw(sf::RenderWindow & window) const {
	window.draw(Animation::getCurrentAnimation());
}

Player::~Player()
{
}
