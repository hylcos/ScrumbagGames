#pragma once
#include "Gun.h"
#include "Knife.h"
class WeaponManager{
public: 
	static WeaponManager& getInstance()
	{
		static WeaponManager instance;
			instance.load();
			return instance;
	}
	void WeaponManager::load();
	Gun * pistol;
	Gun * rifle;
	Gun * shotgun;
	Gun * sniper;
	Knife * dagger;
	Knife * sword;
	
	Weapon * WeaponManager::getOtherWeapon(Weapon * weapon);
	WeaponManager::~WeaponManager();

private:
	
	bool isLoaded = false;
};