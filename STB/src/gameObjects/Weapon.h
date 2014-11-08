#pragma once

#include "GameObject.h"
class Weapon : public GameObject
{
public:
	//! The constructor  of a Weapon
	/*!
	
	*/
	Weapon();

	//! The fire method of a Weapon
	/*!
	Virtual method that will control wat will happen if the Left Mouse Button is Pressed
	*/
	virtual void Weapon::fire();

	//! The update method of a Weapon
	/*!
	Method that will specify what happens when the Weapon is updated
	@param speedModifier The speed of the game based on the framerate
	*/
	void Weapon::update(float speedModifier) override;

	//! The draw method of a Weapon
	/*!
	Virtual method that will specify what happens when a Weapon has to be drawn
	@param window The window the game object has to be drawn in
	*/
	virtual void Weapon::draw(sf::RenderWindow & window) const override;
	
	//! The Reload method of a Weapon
	/*!
	Virtual method that will specify what happens when the R Button is pressed
	*/
	virtual void Weapon::reload();
	
	//! The getAmmo method of a Weapon
	/*!
	Virtual method that will return the amount of ammo the weapon has
	@return amount of ammo
	*/
	virtual float Weapon::getAmmo();
	
	//! The getAmmoScreen method of Weapon
	/*!
	Virtual Method that will return the amount of ammo the weapon has in a string
	@return amount of ammo in a String
	*/
	virtual std::string Weapon::getAmmoString();
	
	//! The getName method of weapon
	/*!
	Virtual Method that will return the name of a Weapon
	@return returns the name of the weapon
	*/
	virtual std::string Weapon::getName();
	
	//! The setAmmo Method of Weapon
	/*!
	Virtual Method that will set the Ammo of the specified weapon
	@param the amount that ammo must be set to
	*/
	virtual void Weapon::setAmmo(int amount);
	
	//! The getDamageLevel method of weapon
	/*!
	Virtual Method that will return the current upgrade level for the damage of the weapon
	@return current DamageLevel
	*/
	virtual int Weapon::getDamageLevel();
	
	//! The upgradeDamage method of weapon
	/*!
	Virtual Method that will upgrade the current Damage
	*/
	virtual void Weapon::upgradeDamage();
	
	//! The getFirerateLevel method of weapon
	/*!
	Virtual Method that will return the current upgrade level for the Fire Rate of the weapon
	@return current Fire Rate Level
	*/
	virtual int Weapon::getFirerateLevel();
	
	//! The upgradeFireRate method of weapon
	/*!
	Virtual Method that will upgrade the current Fire Rate
	*/
	virtual void Weapon::upgradeFireRate();
	
	//! The getReloadSpeedLevel method of weapon
	/*!
	Virtual Method that will return the current upgrade level for the Reload of the weapon
	@return current ReloadLevel
	*/
	virtual int Weapon::getReloadSpeedLevel();
	
	//! The upgradeReloadSpeed method of weapon
	/*!
	Virtual Method that will upgrade the current Reload Speed
	*/
	virtual void Weapon::upgradeReloadSpeed();

	//! The getInfo method of weapon
	/*!
	Virtual Method that will return a string with all the info about a weapon 
	@return the info about the weapon
	*/
	virtual std::string Weapon::getInfo();
	
	//! The getIsReloading method of weapon
	/*!
	Virtual Method that will return if the current weapon is busy with reloading
	@return false = if not reloading, true = if reloading
	*/
	virtual bool Weapon::getIsReloading();
	
	//! The doubleDamage method of weapon
	/*!
	Virtual Method that is called when the powerup DoubleDamage is picked up
	and doubles the damage for a amount of time
	*/
	virtual void Weapon::doubleDamage();
	
	//! The reset method of weapon
	/*!
	Virtual Method that will reset the damage,reloadSpeed,FireRate too there normale state
	*/
	virtual void Weapon::reset();
	
	//! The resetAmmo method of weapon
	/*!
	Virtual Method that will reset the Ammo to there normal state
	*/
	virtual void Weapon::resetAmmo();

	//! The deconstructor  of a Weapon
	/*!

	*/
	~Weapon();
};

