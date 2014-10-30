#pragma once
#include "GameObject.h"
#include "Particle.h"
#include <SFML\Graphics.hpp>
#include <unordered_set>
#include "../SettingsController.h"

class ParticleManager :
	public GameObject
{
public:
	ParticleManager();

	void addParticle(Particle * p);

	void update(float speedModifier) override;
	void move(float speedModifier) override;
	void draw(sf::RenderWindow & window) const override;

	void removeObject(Particle * p);
	void removeAllObjects(Particle * p);

	~ParticleManager();
private:
	std::vector< Particle* > Particles, ParticlesToAdd;
	std::unordered_set<Particle*> ParticlesToRemove;
	bool goreEnabled;
};

