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
	//! The ParticleManager constructor
	/*!
	Checks if Gore is enabled in the settings
	*/
	ParticleManager();

	//! The addParticle Method of ParticalManager
	/*!
	checks if ( Partical is Gore Partical and Gore is enabled) if so
	the partical is added to the ParticalsToAdd vector
	@param p partical that has to be added to the particalManager
	*/
	void addParticle(Particle * p);

	//! The update Method of ParticalManager
	/*!
	adds ParticalsToAdd Particals to main Particals Vector
	Removes all the ParticalsToRemove Partical from the Main Particals Vector
	And Updates all Particals
	@param speedModifier the framerate that calculate on which speed the Particals 
	have to move
	*/
	void update(float speedModifier) override;
	//! The update Method of ParticalManager
	/*!
	Moves all the Particals to there new Position
	@param speedModifier the framerate that calculate on which speed the Particals
	have to move
	*/
	void move(float speedModifier) override;
	//! The draw Method of ParticalManager
	/*!
	Calls the draw function in all the Particals
	@param window the screen on which the Particals has to been draw on.
	*/
	void draw(sf::RenderWindow & window) const override;

	//! The removeObject Method of ParticalManager
	/*!
	Adds a Partical to the list of Particals that have to been deleted
	@param p Partical that have to be Removed
	*/
	void removeObject(Particle * p);
	//! The removeAllObjects Method of ParticalManager
	/*!
	Checks if p exist in Particals Vector. If it does it is deleted
	@param p Partical that have to be Removed
	*/
	void removeAllObjects(Particle * p);

	//! The deconstructor of a ParticleManager
	/*!

	*/
	~ParticleManager();
private:
	std::vector< Particle* > Particles, ParticlesToAdd;
	std::unordered_set<Particle*> ParticlesToRemove ;
	bool goreEnabled;
};

