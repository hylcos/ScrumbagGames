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

	healthForeGround.setFillColor(sf::Color::Red);
	healthBackGround.setFillColor(sf::Color::Black);
	healthBackGround.setSize(sf::Vector2f(type.getHP() / 15.f, 15.f));
	healthBackGround.setOutlineColor(sf::Color::White);
	healthBackGround.setOutlineThickness(2.f);

}
void zoeyBoss::update(float speedModifier) {
	Enemy::update(speedModifier);
	timeToSpawn -= speedModifier;
	showHp();
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
	if (floor(timeToSpawn) <= 0){
		Enemy::draw(window);
		window.draw(healthBackGround);
		window.draw(healthForeGround);
	}
}
void zoeyBoss::move(float speedModifier) {
	if (floor(timeToSpawn) <= 0)
		Enemy::move(speedModifier);
}

void zoeyBoss::showHp()  {
	
	if (spawned){
		healthForeGround.setSize(sf::Vector2f(static_cast<float>(((type.getHP() - dmg) / 15)), 15));
		healthForeGround.setPosition(position.x, position.y - 50);
		healthBackGround.setPosition(position.x, position.y - 50);
		healthForeGround.setOrigin(healthBackGround.getSize().x / 2.0f, healthBackGround.getSize().y / 2.0f);
		healthBackGround.setOrigin(healthBackGround.getSize().x / 2.0f, healthBackGround.getSize().y / 2.0f);
	}
}

void zoeyBoss::reduceHP(int damage){
	if (spawned){
		dmg += damage;
		if (dmg > type.getHP()){
			LevelController::getInstance().getPlayer()->addMoney(1200);
			LevelController::getInstance().getPlayer()->setNextRound(true);
		}
	}
}

zoeyBoss::~zoeyBoss()
{
}
