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
	Gun * pistol = new Gun("pistol", 25, 90.0, 8, 8, 350, 2, 30);
	Gun * rifle = new Gun("rifle", 34, 90.0, 120, 30, 350, 2, 15);
	Gun * shotgun = new Gun("shotgun", 50, 180.0, 60, 6, 350, 10, 45);
	Gun * sniper = new Gun("sniper", 100, 180.0, 50, 4, 999, 15, 60);
	Knife * dagger = new Knife("knife", 34, 70.0, 16);
	Knife * sword = new Knife("sword", 50, 70.0, 32);
	
	WeaponManager::~WeaponManager();

private:
	
	bool isLoaded = false;
};