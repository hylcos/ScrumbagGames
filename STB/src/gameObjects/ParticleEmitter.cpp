#include "../stdafx.h"
#include "ParticleEmitter.h"


ParticleEmitter::ParticleEmitter()
{
}

void ParticleEmitter::setColor(int r, int g, int b, int a){

}

void ParticleEmitter::setColor(sf::Color color){
	particleColor = color;
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
