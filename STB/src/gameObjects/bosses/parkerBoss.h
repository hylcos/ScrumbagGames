#pragma once
#include "../Enemy.h"

class parkerBoss : public Enemy
{
public:
	parkerBoss();
	void parkerBoss::update(float speedModifier) override;
	void parkerBoss::draw(sf::RenderWindow &  window) const override;
	void parkerBoss::move(float speedModifier) override;
	void parkerBoss::reduceHP(int damage) override;
	void parkerBoss::showHp();
	~parkerBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround, healthBackGround;
};

