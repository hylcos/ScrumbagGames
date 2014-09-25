#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"
Player::Player():
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("/Sprites/Player-1.png"), *TextureManager::getInstance().getTexture("/Sprites/Player-2.png"));
}

void Player::update(float speedModifier) {
	curSprite = *Animation::getCurrentAnimation();
	curSprite.setPosition(position);
	
}
void Player::draw(sf::RenderWindow & window) const {
	
	window.draw(curSprite);
}

Player::~Player()
{
}
