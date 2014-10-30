#include "../stdafx.h"
#include "Particle.h"
#include "GameObject.h"
#include "../LevelController.h"
#include "../TextureManager.h"

Particle::Particle(sf::Vector2f pos)
{
	GameObject::position = pos;
}

void Particle::setColor(sf::Color color){
	particle.setFillColor(color);
}

void Particle::setSpeed(float speed){
	particleSpeed = static_cast<float>(rand() % (int)((speed - 0.2f) * 100.f)) / 100.f + 0.2f;
}

void Particle::setDeceleration(float dec){
	deceleration = dec;
}

void Particle::setDirection(float dir, float dev){
	if (dev == 0.f){
		rotation = dir;
	}
	else {
		rotation = static_cast<float>(rand() % (int)(dev * 2) - dev + dir);
	}
}

void Particle::setRotation(float rot, float dev){
	if (dev == 0.f){
		particle.setRotation(rot);
	}
	else {
		particle.setRotation(static_cast<float>(rand() % (int)(dev * 2) - dev + rot));
	}
}

void Particle::setSize(sf::Vector2f size){
	particle.setSize(size);
}

void Particle::setMinimumSpeed(float min){
	minimumSpeed = min;
}

void Particle::setGore(bool g){
	isGore = g;
}

void Particle::update(float speedModifier){
	particleSpeed *= 1.0f - (deceleration * speedModifier);
	if (particleSpeed <= minimumSpeed){
		LevelController::getInstance().getParticleManager()->removeObject(this);
		Particle::~Particle();
	}
}

void Particle::move(float speedModifier){
	prevPosition = position;
	position.x += cos((rotation - 90)*PI / 180) * speedModifier * particleSpeed;
	position.y += sin((rotation - 90)*PI / 180) * speedModifier * particleSpeed;
	particle.setPosition(position);
}

void Particle::draw(sf::RenderWindow & window) const{
	window.draw(particle);
}

bool getGore(){
	return isGore;
}

Particle::~Particle()
{
}
