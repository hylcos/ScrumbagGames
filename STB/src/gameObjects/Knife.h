//! The knife header file
/*!
This is the header file of the knife class.
*/
#pragma once
#include "../stdafx.h"
#include "Weapon.h"
#include "../TextureManager.h"
#include <iostream>
#include "ParticleEmitter.h"

class Knife : public Weapon, ParticleEmitter 
{
public:
	//! The constructor of the knife
	/*!
	Initializes the melee weapon based on the given parametes
	@param name The name of the weapon
	@param damage The amount of damage the weapon deals
	@param attackSpeed The amount of frames in between two attacks
	@param range The range the melee weapon can reach
	*/
	Knife::Knife(std::string name, float damage, short attackSpeed, int range);

	//! The fire method of the knife
	/*!
	Causes the player to attack with his melee weapon.
	*/
	void Knife::fire();
	
	//! The update method of the knife
	/*!
	updates the melee weapon's cooldown and position
	@param speedModifier a modifier for the timings based on the framerate
	*/
	void Knife::update(float speedModifier) override;

	//! The draw method of the knife
	/*!
	draws the knife based on its position and rotation
	@param window The window on which the knife has to be drawn
	*/
	void Knife::draw(sf::RenderWindow & window) const override;

	//! The set rotation method of the knife
	/*!
	Sets the rotation of the knife
	@param rotation the value the knife's rotation should be set to
	*/
	void Knife::setRotation(float rotation);

	//! The getName method of Knife
	/*!
	@return returns the name of the Knife
	*/
	std::string Knife::getName() override;

	//! The getDamageLevel method of weapon
	/*!
	Method that will return the current upgrade level for the damage of the weapon
	@return current DamageLevel
	*/
	int Knife::getDamageLevel() override;

	//! The upgradeDamage method of Knife
	/*!
	Will upgrade the current Damage
	*/
	void Knife::upgradeDamage() override;


	//! The getFirerateLevel method of Knife
	/*!
	will return the current upgrade level for the Fire Rate of the Knife
	@return current Fire Rate Level
	*/
	int Knife::getFirerateLevel() override;

	//! The upgradeFireRate method of Knife
	/*!
	Will upgrade the current Fire Rate
	*/
	void Knife::upgradeFireRate() override;

	//! The reset method of Knife
	/*!
	Will reset the damage and FireRate too there normale state
	*/
	void Knife::reset() override;

	//! The doubleDamage method of Knife
	/*!
	when the powerup DoubleDamage is picked up and doubles the 
	damage for a amount of time
	*/
	void Knife::doubleDamage() override;

	//! The getInfo method of weapon
	/*!
	returns a string with all the info about a Knife
	@return the info about the Knife
	*/
	std::string Knife::getInfo() override;
	//! The deconstructor of the Knife
	/*!
	Deallocates the Knife class.
	*/
	Knife::~Knife();
private:
	sf::Sprite sprite, melee;
	sf::Texture tex, texmelee;
	std::string name;
	bool drawMelee;
	float doubleDamageTimer;
	int damageLevel = 0, fireRateLevel = 0;
	int  range;
	bool doubleDamageEnabled = false;
	float attackSpeed,damage;
	float hitCooldown = 0, rotation;
	
};

