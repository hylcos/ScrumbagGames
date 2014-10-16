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
	Gun * Pistol = new Gun("pistol", 25, 90.0, 8, 8, 350, 2, 30);
	Gun * Uzi = new Gun("uzi", 25, 90.0, 120, 30, 350, 2, 15);
	Gun * Shotgun = new Gun("shotgun", 25, 180.0, 60, 6, 350, 10, 45);
	
	WeaponManager::~WeaponManager();
private:
	
	bool isLoaded = false;
};