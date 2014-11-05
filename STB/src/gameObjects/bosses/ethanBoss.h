#pragma once
#include "../Enemy.h"

class ethanBoss : public Enemy
{
public:
	ethanBoss();
	void ethanBoss::update(float speedModifier) override;
	void ethanBoss::draw(sf::RenderWindow &  window) const override;
	void ethanBoss::move(float speedModifier) override;
	void ethanBoss::reduceHP(int damage) override;
	void ethanBoss::showHp();
	~ethanBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround, healthBackGround;
};

