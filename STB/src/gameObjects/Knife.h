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

	std::string Knife::getName() override;

	int Knife::getDamageLevel() override;
	void Knife::upgradeDamage() override;

	int Knife::getFirerateLevel() override;
	void Knife::upgradeFireRate() override;

	int Knife::getReloadSpeedLevel() override;
	void Knife::upgradeReloadSpeed() override;
	void Knife::reset() override;
	void Knife::doubleDamage() override;
	std::string Knife::getInfo() override;
private:
	sf::Sprite sprite, melee;
	sf::Texture tex, texmelee;
	std::string name;
	bool drawMelee;
	float doubleDamageTimer;
	int damageLevel = 0, fireRateLevel = 0, reloadSpeedLevel = 6;
	int  range;
	bool doubleDamageEnabled = false;
	float attackSpeed,damage;
	float hitCooldown = 0, rotation;
	
};

