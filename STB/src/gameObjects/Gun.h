//! The Gun header file
/*!
This is the header file of the gun class.
*/
#pragma once
#include "../stdafx.h"
#include "Bullet.h"
#include "Weapon.h"
#include "../TextureManager.h"
#include <iostream>

class Gun : public Weapon 
{
public:
	//! The constructor of the gun class
	/*!
	Initializes a gun with the given parameters
	@param name The name of the gun
	@param damage The amount of damage the gun deals
	@param reloadSpeed The time the gun takes to reload
	@param ammo The ammount of ammunition the gun has in total
	@param magazineSize The size of one clip of the gun
	@param range The range the bullets of this gun can travel
	@param bulletSpeed The speed with which the bullets travel
	@param fireRate The amount of frames in between two shots
	*/
	Gun::Gun(std::string name,float damage, float reloadSpeed,int ammo,int magazineSize,int range, short bulletSpeed,short fireRate);

	//! The fire method of the gun
	/*!
	This method will check if there is sufficient ammunition for the
	gun to fire, and if it is not on cooldown or reloading.
	Then it will check where the mouse is located and create a bullet
	heading in the direction of the mouse cursor.
	*/
	void Gun::fire() override;

	//! The update method of the gun
	/*!
	reduces the cooldown and reload time of the gun accordingly to the framerate.
	Also updates the position and rotation of the gun.
	@param speedModifier the amount of time subtracted from the cooldown and reload time based on the framerate.
	*/
	void Gun::update(float speedModifier) override;

	//! The draw method of the gun
	/*!
	Draws the sprite of the gun on the screen
	@param window The window the gun has to be drawn on
	*/
	void Gun::draw(sf::RenderWindow & window) const override;

	//! The setRotation method of the gun
	/*!
	@param rotation The value the rotation of the gun has to be set to.
	*/
	void Gun::setRotation(float rotation) override;

	//! The reload method of the gun
	/*!
	Checks for some factors if the gun is able to reload and then refills the magazine.
	*/
	void Gun::reload() override;

	//! The getAmmo method of the gun
	/*!
	@returns The amount of ammunition the gun has left
	*/
	float Gun::getAmmo() override;

	//! The upgradeDamage method of the gun
	/*!
	@param amount The amount with which the damage of the gun has to be increased.
	*/
	void Gun::upgradeDmg(int amount);

	//! The upgradeFireRate method of the gun
	/*!
	@param amount The amount of frames the relead time of the gun has to be reduced with.
	*/
	void Gun::upgradeFireRate(short amount);


	int Gun::getDamageLevel() override;
	void Gun::upgradeDamage() override;

	int Gun::getFirerateLevel() override;
	void Gun::upgradeFireRate() override;

	int Gun::getReloadSpeedLevel() override;
	void Gun::upgradeReloadSpeed() override;

	std::string Gun::getInfo() override;
	
	void Gun::doubleDamage();
	std::string Gun::getAmmoString() override;
	std::string Gun::getName() override;
	Gun Gun::getWeapon();
	void Gun::setAmmo(int amount);
	bool Gun::getIsReloading() override;

	void Gun::reset() override;
	void Gun::resetAmmo() override;

	//! The deconstructor of the gun
	/*!
	Deallocates the gun class.
	*/
	Gun::~Gun();
private:
	float doubleDamageTimer;
	bool isReloading = false;
	sf::Sprite sprite;
	sf::Texture tex;
	std::string name;
	bool doubleDamageEnabled = false;
	int damageLevel = 0, fireRateLevel = 0, reloadSpeedLevel = 0;
	int magazineSize, range, ammo, currentMagazine, startAmmo;
	float damage, fireRate, oldDamage;
	short bulletSpeed;
	float reloadSpeed,rotation,shootCoolDown,reloadCoolDown;
};

