#include "../stdafx.h"
#include "ParticleEmitter.h"
#include "../LevelController.h"
#include <iostream>

ParticleEmitter::ParticleEmitter()
{
}

void ParticleEmitter::update(float speedModifier){
	if (particleManager == nullptr){
		particleManager = LevelController::getInstance().getParticleManager();
	}
	frame++;
	if ((frame >= frequency / speedModifier && emit) || emitOnce){
		emitOnce = false;
		int p = rand() % (amount - 1) + 1;
		for (int i = 0; i < p; i++){
			Particle * p;
			if (position.x == 0){
				p = new Particle(object->getPosition());
			}
			else {
				p = new Particle(position);
			}
			p->setColor(particleColor);
			p->setSpeed(speed);
			p->setDeceleration(deceleration);
			p->setDirection(direction, directionDeviation);
			p->setSize(size);
			p->setRotation(rotation, rotationDeviation);
			p->setMinimumSpeed(minimumSpeed);
			p->setGore(isGore);
			particleManager->addParticle(p);
		}
		//particleManager->spawnParticles(object, particleColor, rand() % (amount - 1) + 1);
		frame = 0;
	}
}

void ParticleEmitter::setColor(int r, int g, int b, int a){
	particleColor.r = r;
	particleColor.g = g;
	particleColor.b = b;
	particleColor.a = a;
}

void ParticleEmitter::setColor(sf::Color color, int a){
	particleColor = color;
	particleColor.a = a;
}

float ParticleEmitter::getFrequency(){
	return frequency;
}

int ParticleEmitter::getParticleAmount(){
	return amount;
}

void ParticleEmitter::setSize(float sizeX, float sizeY){
	if (sizeY == 0){
		sizeY = sizeX;
	}
	size = sf::Vector2f{ sizeX, sizeY };
}

bool ParticleEmitter::getGore(){
	return isGore;
}

ParticleEmitter::~ParticleEmitter()
{
}
