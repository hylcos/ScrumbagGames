#pragma once
#include "../Enemy.h"

class bobbyBoss : public Enemy
{
public:
	bobbyBoss();
	void bobbyBoss::update(float speedModifier) override;
	void bobbyBoss::draw(sf::RenderWindow &  window) const override;
	void bobbyBoss::move(float speedModifier) override;
	void bobbyBoss::reduceHP(int damage) override;

	~bobbyBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
};

