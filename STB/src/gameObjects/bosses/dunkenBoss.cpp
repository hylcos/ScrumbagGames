#include "../../stdafx.h"
#include "dunkenBoss.h"


dunkenBoss::dunkenBoss():
Enemy{}
{
	Enemy::setType(Enemy::dunken);
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/4.png"));
	sf::Texture tex = *TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/melee.png");
	Enemy::melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
	
}
void dunkenBoss::update(float speedModifier) {
	Enemy::update(speedModifier);
	timeToSpawn -= speedModifier;
}
void dunkenBoss::draw(sf::RenderWindow &  window) const {
	Enemy::draw(window);
}
void dunkenBoss::move(float speedModifier) {
	Enemy::move(speedModifier);
}


dunkenBoss::~dunkenBoss()
{
}
