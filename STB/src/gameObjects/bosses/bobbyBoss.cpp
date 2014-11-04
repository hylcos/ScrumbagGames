#include "../../stdafx.h"
#include "bobbyBoss.h"
#include "../../LevelController.h"

bobbyBoss::bobbyBoss()
{
	//std::cout << "Bobby\n";
	Enemy::type = bobby;
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Bobby/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Bobby/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Bobby/3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Bobby/4.png"));
	tex = *TextureManager::getInstance().getTexture("Sprites/Bosses/Bobby/4.png");
	melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
	timeToSpawn = 5400;

}
void bobbyBoss::update(float speedModifier) {
	Enemy::update(speedModifier);
	timeToSpawn -= speedModifier;
	if (floor(timeToSpawn) > 0)
		HudController::getInstance().updateTimer(timeToSpawn);
	else if (spawned == false) {
		if (LevelController::getInstance().curLevel == 4){
			spawned = true;
			std::cout << "bobby has spwn";
			int random = rand() % 360;
			float radius = random * PI / 180;
			position.x = LevelController::getInstance().getPlayer()->getPosition().x + cos(radius) * 640;
			position.y = LevelController::getInstance().getPlayer()->getPosition().y + sin(radius) * 480;
			HudController::getInstance().updateTimer("BOSS");
		}
	}

}
void bobbyBoss::draw(sf::RenderWindow &  window) const {
	if (floor(timeToSpawn) <= 0)
		Enemy::draw(window);
}
void bobbyBoss::move(float speedModifier) {
	if (floor(timeToSpawn) <= 0)
		Enemy::move(speedModifier);
}

void bobbyBoss::reduceHP(int damage){
	if (spawned){
		dmg += damage;
		if (dmg > type.getHP()){
			LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
		}
	}
}

bobbyBoss::~bobbyBoss()
{
}
