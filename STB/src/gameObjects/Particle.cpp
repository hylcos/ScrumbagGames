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
	GameObject::position = pos;
	particleSpeed = static_cast<float>(rand() % 2 + 3);
	rotation = static_cast<float>(rand() % 360);
	particle.setRotation(rotation);
}

void Particle::update(float speedModifier){
	particleSpeed *= 1.0f - (0.1f * speedModifier);
	if (particleSpeed <= 0.01){
		LevelController::getInstance().removeObject(this);
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
