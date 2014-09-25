#include "../stdafx.h"
#include "Player.h"
#include "../TextureManager.h"

struct { sf::Keyboard::Key key; float x; float y;} actions[] = {
	{ sf::Keyboard::A, -1.0, 0.0 },
	{ sf::Keyboard::D, 1.0, 0.0 },
	{ sf::Keyboard::W, 0.0, -1.0 },
	{ sf::Keyboard::S, 0.0, 1.0}
};

Player::Player():
Animation{}
{
	Animation::setTextures(*TextureManager::getInstance().getTexture("Sprites/Players/Player-1.png"), 
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Players/Player-4.png"));
}

void Player::update(float speedModifier) {
	curSprite = *Animation::getCurrentAnimation();
	curSprite.setPosition(position);
	curSprite.setRotation(rotation);
	if (toNext >= 10){
		Animation::next();
		toNext -= 10;
	}
}

void Player::move(float speedModifier){
	sf::Vector2f newPos{ 0, 0 };
	for (auto & action : actions){
		if (sf::Keyboard::isKeyPressed(action.key)){
			newPos.x += action.x;
			newPos.y += action.y;
		}
	}
	if (newPos != sf::Vector2f{ 0, 0 }){
		float dir = atan2(newPos.y, newPos.x);
		rotation = dir * 180 / 3.14159265358979323846f + 90;
		position.x += cos(dir) * speedModifier;
		position.y += sin(dir) * speedModifier;
		toNext += speedModifier;
	}
	
}
void Player::draw(sf::RenderWindow & window) const {
	
	window.draw(curSprite);
}

Player::~Player()
{
}
