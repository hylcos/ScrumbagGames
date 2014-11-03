#include "WeaponManager.h"
void WeaponManager::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;
	pistol = new Gun("pistol", 25, 90.0, 8, 8, 350, 8, 30);
	rifle = new Gun("rifle", 34, 90.0, 120, 30, 350, 8, 15);
	shotgun = new Gun("shotgun", 50, 180.0, 60, 6, 350, 20, 45);
	sniper = new Gun("sniper", 150, 180.0, 50, 4, 999, 30, 60);
	dagger = new Knife("dagger", 34, 70, 16);
	sword = new Knife("sword", 50, 70, 32);

}


Weapon * WeaponManager::getOtherWeapon(Weapon * weapon){
	if (weapon == pistol)
		return rifle;
	if (weapon == rifle)
		return pistol;

	if (weapon == shotgun)
		return sniper;
	if (weapon == sniper)
		return shotgun;

	if (weapon == sword)
		return dagger;
	if (weapon == dagger)
		return sword;


	return nullptr;
}
WeaponManager::~WeaponManager(){}