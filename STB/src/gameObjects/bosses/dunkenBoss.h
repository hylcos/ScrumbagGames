#pragma once
#include "../../LevelController.h"
class dunkenBoss : public Enemy
{
public:
	dunkenBoss();
	void dunkenBoss::update(float speedModifier) override;
	void dunkenBoss::draw(sf::RenderWindow &  window) const override;
	void dunkenBoss::move(float speedModifier) override;


	~dunkenBoss();
private:
	float timeToSpawn = 9000;
};

