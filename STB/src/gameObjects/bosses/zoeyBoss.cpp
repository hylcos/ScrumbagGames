#include "../../stdafx.h"
#include "zoeyBoss.h"
#include "../../LevelController.h"

zoeyBoss::zoeyBoss()
{
	std::cout << "Zoey\n";
	Enemy::type = zoey;
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Zoey/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Zoey/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Zoey/3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Zoey/4.png"));
	tex = *TextureManager::getInstance().getTexture("Sprites/Bosses/Zoey/melee.png");
	melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
	timeToSpawn = 5400;

}
void zoeyBoss::update(float speedModifier) {
	Enemy::update(speedModifier);
	timeToSpawn -= speedModifier;
	if (floor(timeToSpawn) > 0)
		HudController::getInstance().updateTimer(timeToSpawn);
	else if (spawned == false) {
			spawned = true;
			std::cout << "zoey has spwn";
			int random = rand() % 360;
			float radius = random * PI / 180;
			position.x = LevelController::getInstance().getPlayer()->getPosition().x + cos(radius) * 640;
			position.y = LevelController::getInstance().getPlayer()->getPosition().y + sin(radius) * 480;
			HudController::getInstance().updateTimer("BOSS");
	}

}
void zoeyBoss::draw(sf::RenderWindow &  window) const {
	if (floor(timeToSpawn) <= 0)
		Enemy::draw(window);
}
void zoeyBoss::move(float speedModifier) {
	if (floor(timeToSpawn) <= 0)
		Enemy::move(speedModifier);
}

void zoeyBoss::reduceHP(int damage){
	if (spawned){
		dmg += damage;
		if (dmg > type.getHP()){

			LevelController::getInstance().getPlayer()->addMoney(1200);
			LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
		}
	}
}

zoeyBoss::~zoeyBoss()
{
}
