#include "../stdafx.h"
#include "ParticleEmitter.h"
#include <iostream>
#include "../LevelController.h"

ParticleEmitter::ParticleEmitter()
{
}

void ParticleEmitter::emitParticles(){
	for (int i = rand() % ((int)(amount / 2)) + (int)(amount / 2); i > 0; i--){
		Particle * p;
		if (spawnPosition.x == 0){
			p = new Particle(object->getPosition());
		}
		else {
			p = new Particle(spawnPosition);
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
}

void ParticleEmitter::update(float speedModifier){
	if (particleManager == nullptr){
		particleManager = LevelController::getInstance().getParticleManager();
	}
	frame++;
	if ((frame >= frequency / speedModifier && emit) || emitOnce){
		emitOnce = false;
		emitParticles();
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

bool ParticleEmitter::getGore(){
	return isGore;
}

ParticleEmitter::~ParticleEmitter()
{
}
