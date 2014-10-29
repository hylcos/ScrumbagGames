#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleManager.h"
class ParticleEmitter
{
public:
	ParticleEmitter();
	void update(float speedModifier);
	void setColor(int r, int g, int b, int a);
	void setColor(sf::Color color, int a = 0);
	bool isEmitting();
	float getFrequency();
	int getParticleAmount();
	~ParticleEmitter();
protected:
	sf::Color particleColor;
	bool emitOnce = false;
	bool emit = false;
	float frequency = 30;
	int amount = 1;
	int frame = 0;
	ParticleManager * particleManager = nullptr;
	GameObject * object;
};

