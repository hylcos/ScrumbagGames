#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleManager.h"
class ParticleEmitter
{
public:
	//! The ParticleManager constructor
	/*!
	*/
	ParticleEmitter();

	//! The emitParticles Method of ParticalEmitter
	/*!
	Spawns a given Amount of Particals and sets all there Attributes
	*/
	void ParticleEmitter::emitParticles();
	//! The update Method of ParticalEmitter
	/*!
	Gets the ParticalManager is called for the first time
	If the number of past frames is more or equal then the spawnrate 
	of the ParticalEmmiter there will spawn a new bunch of Particals
	@param speedModifier the speed of the game
	*/
	void ParticleEmitter::update(float speedModifier);

	//! The setColor Method of ParticalEmitter
	/*!
	sets the color of the particals that have to been spawned
	@param r How much Red
	@param g How much Green
	@param b How much Blue
	@param a How much the Opacity is
	*/
	void ParticleEmitter::setColor(int r, int g, int b, int a);

	//! The setColor Method of ParticalEmitter
	/*!
	sets the color of the particals that have to been spawned
	@param color the base Color of the Particals
	@param a How much the Opacity is
	*/
	void ParticleEmitter::setColor(sf::Color color, int a = 255);

	//! The deconstructor of a ParticleEmitter
	/*!

	*/
	~ParticleEmitter();
protected:
	sf::Color particleColor;
	bool emitOnce = false;
	bool emit = false;
	bool isGore = false;
	float frequency = 30.f;
	int amount = 1;
	int frame = 0;
	float speed = 20.f;
	float deceleration = 0.15f;
	float direction = 0.f;
	float directionDeviation = 360.f;
	float size = 2.f;
	float rotation = 0.f;
	float rotationDeviation = 360.f;
	float minimumSpeed = 0.004f;
	sf::Vector2f spawnPosition{ 0, 0 };
	
	ParticleManager * particleManager = nullptr;
	GameObject * object = nullptr;
};

