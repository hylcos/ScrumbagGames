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
	if (frame >= frequency / speedModifier){
		if (isEmitting()){
			int p = rand() % (amount - 1) + 1;
			for (int i = 0; i < p; i++){
				Particle * p = new Particle(object->getPosition());
				p->setColor(particleColor);
				p->setSpeed(speed);
				p->setDeceleration(deceleration);
				particleManager->addParticle(p);
			}
			//particleManager->spawnParticles(object, particleColor, rand() % (amount - 1) + 1);
			frame = 0;
		}
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

bool ParticleEmitter::isEmitting(){
	if (emit){
		return emit;
	}
	if (emitOnce){
		emitOnce = false;
		return true;
	}
	return false;
}

float ParticleEmitter::getFrequency(){
	return frequency;
}

int ParticleEmitter::getParticleAmount(){
	return amount;
}

ParticleEmitter::~ParticleEmitter()
{
}
