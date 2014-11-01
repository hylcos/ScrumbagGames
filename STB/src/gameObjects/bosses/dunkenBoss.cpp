#include "../../stdafx.h"
#include "dunkenBoss.h"
#include "../../LevelController.h"

dunkenBoss::dunkenBoss()
{
	std::cout << "Dunken\n";
	Enemy::type = dunken;
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/4.png"));
	tex = *TextureManager::getInstance().getTexture("Sprites/Bosses/Dunken/melee.png");
	melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
	timeToSpawn = 300;
	
}
void dunkenBoss::update(float speedModifier) {
		Enemy::update(speedModifier);
		timeToSpawn -= speedModifier;
		if (floor(timeToSpawn) > 0 )
			HudController::getInstance().updateTimer(timeToSpawn);
		else if (spawned == false) {
			spawned = true;
			std::cout << "boss has spwn";
			int random = rand() % 360;
			float radius = random * PI / 180;
			position.x = LevelController::getInstance().getPlayer()->getPosition().x + cos(radius) * 640;
			position.y = LevelController::getInstance().getPlayer()->getPosition().y + sin(radius) * 480;
			HudController::getInstance().updateTimer("BOSS");
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
	dmg += damage;
	if (dmg > type.getHP()){
		LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
	}
}

dunkenBoss::~dunkenBoss()
{
}
