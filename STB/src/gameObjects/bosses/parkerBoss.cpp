#include "../../stdafx.h"
#include "parkerBoss.h"
#include "../../LevelController.h"

parkerBoss::parkerBoss()
{
	std::cout << "Parker\n";
	Enemy::type = parker;
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Parker/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Parker/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Parker/3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Parker/4.png"));
	tex = *TextureManager::getInstance().getTexture("Sprites/Bosses/Parker/4.png");
	melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
	timeToSpawn = 5400;

}
void parkerBoss::update(float speedModifier) {
	Enemy::update(speedModifier);
	timeToSpawn -= speedModifier;
	if (floor(timeToSpawn) > 0)
		HudController::getInstance().updateTimer(timeToSpawn);
	else if (spawned == false) {
		if (LevelController::getInstance().curLevel == 3){
			spawned = true;
			std::cout << "parker has spwn";
			int random = rand() % 360;
			float radius = random * PI / 180;
			position.x = LevelController::getInstance().getPlayer()->getPosition().x + cos(radius) * 640;
			position.y = LevelController::getInstance().getPlayer()->getPosition().y + sin(radius) * 480;
			HudController::getInstance().updateTimer("BOSS");
		}
	}

}
void parkerBoss::draw(sf::RenderWindow &  window) const {
	if (floor(timeToSpawn) <= 0)
		Enemy::draw(window);
}
void parkerBoss::move(float speedModifier) {
	if (floor(timeToSpawn) <= 0)
		Enemy::move(speedModifier);
}

void parkerBoss::reduceHP(int damage){
	if (spawned){
		dmg += damage;
		if (dmg > type.getHP()){
			LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
		}
	}
}

parkerBoss::~parkerBoss()
{
}
