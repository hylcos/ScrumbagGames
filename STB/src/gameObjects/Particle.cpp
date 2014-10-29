#include "../stdafx.h"
#include "Particle.h"
#include "GameObject.h"
#include "../LevelController.h"
#include "../TextureManager.h"

Particle::Particle(sf::Vector2f pos)
{
	particle = sf::RectangleShape{};
	particle.setSize(sf::Vector2f{ 4.0, 4.0 });
	particle.setFillColor(sf::Color::Black);
	particleSpeed = static_cast<float>(rand() % 200) / 100.f + 1.f;
	rotation = static_cast<float>(rand() % 360);
	particle.setRotation(rotation);
	GameObject::position = pos;
}

void Particle::setColor(sf::Color color){
	particle.setFillColor(color);
}

void Particle::setSpeed(float speed){
	particleSpeed = static_cast<float>(rand() % (int)((speed - 1.f) * 100.f)) / 100.f + 1.f;
}

void Particle::setDeceleration(float dec){
	deceleration = dec;
}

void Particle::update(float speedModifier){
	particleSpeed *= 1.0f - (deceleration * speedModifier);
	if (particleSpeed <= 0.004){
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

Particle::~Particle()
{
}
