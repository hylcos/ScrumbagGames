#include "../../stdafx.h"
#include "ethanBoss.h"
#include "../../LevelController.h"

ethanBoss::ethanBoss()
{
	std::cout << "Ethan\n";
	Enemy::type = ethan;
	Animation::setTextures(
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Ethan/1.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Ethan/2.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Ethan/3.png"),
		*TextureManager::getInstance().getTexture("Sprites/Bosses/Ethan/4.png"));
	tex = *TextureManager::getInstance().getTexture("Sprites/Bosses/Ethan/4.png");
	melee.setTexture(tex);
	melee.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
	timeToSpawn = 5400;

}
void ethanBoss::update(float speedModifier) {
	Enemy::update(speedModifier);
	timeToSpawn -= speedModifier;
	showHp();
	if (floor(timeToSpawn) > 0)
		HudController::getInstance().updateTimer(timeToSpawn);
	else if (spawned == false) {
			spawned = true;
			std::cout << "ethan has spwn";
			int random = rand() % 360;
			float radius = random * PI / 180;
			position.x = LevelController::getInstance().getPlayer()->getPosition().x + cos(radius) * 640;
			position.y = LevelController::getInstance().getPlayer()->getPosition().y + sin(radius) * 480;
			HudController::getInstance().updateTimer("BOSS");
	}

}
void ethanBoss::draw(sf::RenderWindow &  window) const {
	if (floor(timeToSpawn) <= 0){
		Enemy::draw(window);
		window.draw(healthBackGround);
		window.draw(healthForeGround);
	}
}
void ethanBoss::move(float speedModifier) {
	if (floor(timeToSpawn) <= 0)
		Enemy::move(speedModifier);
}

void ethanBoss::showHp()  {

	if (spawned){
		healthForeGround.setSize(sf::Vector2f(static_cast<float>(((type.getHP() - dmg) / 15)), 15));
		healthForeGround.setPosition(position.x, position.y - 50);
		healthBackGround.setPosition(position.x, position.y - 50);
		healthForeGround.setOrigin(healthBackGround.getSize().x / 2.0f, healthBackGround.getSize().y / 2.0f);
		healthBackGround.setOrigin(healthBackGround.getSize().x / 2.0f, healthBackGround.getSize().y / 2.0f);
	}
}


void ethanBoss::reduceHP(int damage){
	if (spawned){
		dmg += damage;
		if (dmg > type.getHP()){
			LevelController::getInstance().getPlayer()->addMoney(800);
			LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
		}
	}
}

ethanBoss::~ethanBoss()
{
}
