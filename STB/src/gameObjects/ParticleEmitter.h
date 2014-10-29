#pragma once
#include <SFML/Graphics.hpp>
class ParticleEmitter
{
public:
	ParticleEmitter();
	void setColor(int r, int g, int b, int a);
	void setColor(sf::Color color);
	bool isEmitting();
	float getFrequency();
	int getParticleAmount();
	~ParticleEmitter();
protected:
	sf::Color particleColor;
	bool emitOnce = false;
	bool emit = false;
	float frequency = 60;
	int amount = 1;
};

