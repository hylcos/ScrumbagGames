#pragma once
#include "../Enemy.h"

class zoeyBoss : public Enemy
{
public:
	zoeyBoss();
	void zoeyBoss::update(float speedModifier) override;
	void zoeyBoss::draw(sf::RenderWindow &  window) const override;
	void zoeyBoss::move(float speedModifier) override;
	void zoeyBoss::reduceHP(int damage) override;
	void zoeyBoss::showHp();
	~zoeyBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround,healthBackGround;
};

