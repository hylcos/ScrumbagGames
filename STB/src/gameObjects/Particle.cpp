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
	position.x += cos((rotation - 90)*PI / 180) * particleSpeed * 3;
	position.y += sin((rotation - 90)*PI / 180) * particleSpeed * 3;
}

void Particle::update(float speedModifier){
	particleSpeed *= 1.0f - (0.15f * speedModifier);
	if (particleSpeed <= 0.004){
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
