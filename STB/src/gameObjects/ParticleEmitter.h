#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleManager.h"
class ParticleEmitter
{
public:
	ParticleEmitter();
	void ParticleEmitter::emitParticles();
	void ParticleEmitter::update(float speedModifier);
	void ParticleEmitter::setColor(int r, int g, int b, int a);
	void ParticleEmitter::setColor(sf::Color color, int a = 255);
	bool ParticleEmitter::isEmitting();
	float ParticleEmitter::getFrequency();
	int ParticleEmitter::getParticleAmount();
	bool ParticleEmitter::getGore();
	~ParticleEmitter();
protected:
	sf::Color particleColor;
	bool emitOnce = false;
	bool emit = false;
	bool isGore = false;
	float frequency = 30.f;
	int amount = 1;
	int frame = 0;
	float speed = 20.f;
	float deceleration = 0.15f;
	float direction = 0.f;
	float directionDeviation = 360.f;
	float size = 2.f;
	float rotation = 0.f;
	float rotationDeviation = 360.f;
	float minimumSpeed = 0.004f;
	sf::Vector2f spawnPosition{ 0, 0 };
	
	ParticleManager * particleManager = nullptr;
	GameObject * object;
};

