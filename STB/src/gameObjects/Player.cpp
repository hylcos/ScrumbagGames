#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"
struct { sf::Keyboard::Key key; float x; float y; } actions[] = {
	{ sf::Keyboard::Left, -1.0, 0.0 },
	{ sf::Keyboard::Right, 1.0, 0.0 },
	{ sf::Keyboard::Up, 0.0, -1.0 },
	{ sf::Keyboard::Down, 0.0, 1.0 }
};

Player::Player():
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("/Sprites/Players/Player-1.png"), *TextureManager::getInstance().getTexture("/Sprites/Players/Player-2.png"));
}

void Player::update(float speedModifier) {
	curSprite = *Animation::getCurrentAnimation();
	curSprite.setPosition(position);
}
void Player::move(float speedModifier){
	sf::Vector2f newPos{ 0, 0 };
	for (auto & action : actions){
		if (sf::Keyboard::isKeyPressed(action.key)){
			newPos.x += action.x;
			newPos.y += action.y;
		}
	}
	newPos *= speedModifier;
	position += newPos;
}
void Player::draw(sf::RenderWindow & window) const {
	
	window.draw(curSprite);
}

Player::~Player()
{
}
