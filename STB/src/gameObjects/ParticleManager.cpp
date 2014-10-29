#include "../stdafx.h"
#include "ParticleManager.h"
#include <SFML\Graphics.hpp>

ParticleManager::ParticleManager() :
GameObject{ particleManager }
{
}

void ParticleManager::update(float speedModifier) {
	for (Particle * p : ParticlesToAdd){
		Particles.push_back(p);
	}
	ParticlesToAdd.clear();

	for (Particle * p : ParticlesToRemove){
		ParticleManager::removeAllObjects(p);
	}
	ParticlesToRemove.clear();
}

void ParticleManager::move(float speedModifier) {
	for (Particle * p : Particles){
		p->move(speedModifier);
	}
}

void ParticleManager::draw(sf::RenderWindow & window) const {
	for (Particle * p : Particles){
		p->draw(window);
	}
}

void ParticleManager::removeObject(Particle * p){
	ParticlesToRemove.insert(p);
}

void ParticleManager::removeAllObjects(Particle * p){
	if (p == nullptr){
		return;
	}
	std::vector<Particle*>::iterator position = std::find(Particles.begin(), Particles.end(), p);
	delete p;
	if (position != Particles.end()) // == vector.end() means the element was not found
		Particles.erase(position);
}

ParticleManager::~ParticleManager()
{
}
