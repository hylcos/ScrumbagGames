#pragma once
#include "../Enemy.h"

class dunkenBoss : public Enemy
{
public:
	dunkenBoss();
	void dunkenBoss::update(float speedModifier) override;
	void dunkenBoss::draw(sf::RenderWindow &  window) const override;
	void dunkenBoss::move(float speedModifier) override;
	void dunkenBoss::reduceHP(int damage) override;

	~dunkenBoss();
private:
	float timeToSpawn = 300;
};

