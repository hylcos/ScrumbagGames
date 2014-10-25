#include "WeaponManager.h"
void WeaponManager::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;
	pistol = new Gun("pistol", 25, 90.0, 8, 8, 350, 2, 30);
	rifle = new Gun("rifle", 34, 90.0, 120, 30, 350, 2, 15);
	shotgun = new Gun("shotgun", 50, 180.0, 60, 6, 350, 10, 45);
	sniper = new Gun("sniper", 100, 180.0, 50, 4, 999, 15, 60);
	dagger = new Knife("knife", 34, 70, 16);
	sword = new Knife("sword", 50, 70, 32);

}
WeaponManager::~WeaponManager(){}