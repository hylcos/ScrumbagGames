#pragma once
#include "Gun.h"
#include "Knife.h"
class WeaponManager{
public: 
	//!The getInsatnce method of the WeaponManager
	/*!
	This method makes sure there is only 1 instance of the WeaponManager at a time.
	This way, every time an external class uses a WeaponManager, it uses a WeaponManager
	with the same attributes as every other class.
	@return The instance of the WeaponManager
	*/
	static WeaponManager& getInstance()
	{
		static WeaponManager instance;
			instance.load();
			return instance;
	}
	//! The load method of the WeaponManager
	/*!
	This method will set all the standard values for the WeaponManager
	*/
	void WeaponManager::load();

	Gun * pistol;
	Gun * rifle;
	Gun * shotgun;
	Gun * sniper;
	Knife * dagger;
	Knife * sword;

	//! The getOtherWeapon of the WeaponManager
	/*!
	This method will check in which tier the given weapon is and returns the other weapon in the same tier
	@param weapon that needs to be switched
	@return the other weapon in the tier then the one who is being send
	*/
	Weapon * WeaponManager::getOtherWeapon(Weapon * weapon);

	WeaponManager::~WeaponManager();

private:
	
	bool isLoaded = false;
};