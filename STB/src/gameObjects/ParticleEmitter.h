#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleManager.h"
class ParticleEmitter
{
public:
	ParticleEmitter();
	void update(float speedModifier);
	void setColor(int r, int g, int b, int a);
	void setColor(sf::Color color, int a = 255);
	bool isEmitting();
	float getFrequency();
	int getParticleAmount();
	void setSize(float sizeX, float sizeY = 0.f);
	~ParticleEmitter();
protected:
	sf::Color particleColor;
	bool emitOnce = false;
	bool emit = false;
	float frequency = 30.f;
	int amount = 1;
	int frame = 0;
	float speed = 20.f;
	float deceleration = 0.15f;
	float direction = 0.f;
	float directionDeviation = 360.f;
	sf::Vector2f size{ 0, 0 };
	float rotation = 0.f;
	float rotationDeviation = 360.f;
	
	ParticleManager * particleManager = nullptr;
	GameObject * object;
};

