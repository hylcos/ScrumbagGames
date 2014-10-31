#include "../../stdafx.h"
#include "dunkenBoss.h"
#include "../../LevelController.h"

dunkenBoss::dunkenBoss():
Enemy{}
{
	std::cout << "Dunken\n";
	Enemy::type = dunken;
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
	if (floor(timeToSpawn) <= 0)
		Enemy::update(speedModifier);
	else{
		timeToSpawn -= speedModifier;
		HudController::getInstance().updateTimer(timeToSpawn);
	}
}
void dunkenBoss::draw(sf::RenderWindow &  window) const {
	if (floor(timeToSpawn) <= 0)
		Enemy::draw(window);
}
void dunkenBoss::move(float speedModifier) {
	if (floor(timeToSpawn) <= 0)
		Enemy::move(speedModifier);
}

void dunkenBoss::reduceHP(int damage){
	Enemy::reduceHP(damage);
	if (dmg > type.getHP()){
		LevelController::getInstance().goToNextLevel(&LevelController::getInstance().LEVEL_TWO);
	}
}

dunkenBoss::~dunkenBoss()
{
}
