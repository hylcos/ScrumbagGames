
#include "Gun.h"
#include "../LevelController.h"
Gun::Gun(std::string name, float damage, float reloadSpeed, int ammo, int magazineSize, short bulletSpeed, short fireRate) :
damage{ damage },
reloadSpeed{ reloadSpeed },
magazineSize{ magazineSize },
bulletSpeed{ bulletSpeed },
fireRate{ fireRate },
ammo{ ammo },
startAmmo{ ammo }
{
	Gun::name = name;
	tex = *TextureManager::getInstance().getTexture("Sprites/Weapons/"+name + ".png");
	TextureManager::getInstance().getTexture("Sprites/Weapons/"+name + "_bullet.png");
	sprite.setTexture(tex);
	sprite.setOrigin(tex.getSize().x / 2.0f, tex.getSize().x*1.5f);
	ammo -= magazineSize;
	currentMagazine = magazineSize;
	oldDamage = damage;
}

void Gun::fire(){
	if (ammo >= 0 && currentMagazine > 0){
		if (reloadCoolDown <= 0){
			if (shootCoolDown <= 0){
				position.x += (10 * cos(rotation * PI / 180)
					+ 15 * cos((rotation - 90) * PI / 180));
				position.y += (10 * sin(rotation* PI / 180)
					+ 15 * sin((rotation - 90) * PI / 180));
				SoundController::getInstance().playMusic(name);
				Bullet * newBullet = new Bullet("Sprites/Weapons/" + name + "_bullet.png", rotation, bulletSpeed, static_cast<int>(damage)* (doubleDamageEnabled?2:1), position);
				LevelController::getInstance().addObject(newBullet);
				shootCoolDown = fireRate;
				currentMagazine--;
				
				std::cout << "Ammo: " << currentMagazine << "/" << magazineSize << "/" << ammo <<"\n";
				if (currentMagazine <= 0){
					reload();
				}
			}
		}
	}
	else {

		std::cout << "No More ammo \n";
	}
	
}

std::string Gun::getAmmoString(){
	if (name == "pistol"){
		std::string Ammo{ std::to_string(currentMagazine) + "/ inf" };
		return Ammo;
	}
	else{
		std::string Ammo{ std::to_string(currentMagazine) + "/" + std::to_string(ammo) };
		return Ammo;
	}
	
}

void Gun::setRotation(float rotation){
	this->rotation = rotation;
}

void Gun::update(float speedModifier) {
	shootCoolDown -= speedModifier;
	reloadCoolDown -= speedModifier;
	sprite.setPosition(position);
	sprite.setRotation(rotation);
	doubleDamageTimer -= speedModifier;
	if (doubleDamageTimer <= 0 && doubleDamageEnabled){
		doubleDamageEnabled = false;
	}
}

std::string Gun::getName(){
	return name;
}

void Gun::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
bool Gun::getIsReloading(){
	if (reloadCoolDown <= 0){
		isReloading = false;
	}
	else {
		isReloading = true;
	}
	return isReloading;
}

void Gun::reload(){
	if (ammo > 0){
		if (reloadCoolDown <= 0){
			SoundController::getInstance().playMusic(name + "_reload");
			if (magazineSize <= ammo){
				reloadCoolDown = reloadSpeed;
				if (currentMagazine > 0){
					ammo += currentMagazine;
				}
				currentMagazine = magazineSize;
				ammo -= currentMagazine;
				if (name == "pistol"){
					ammo = 8;
				}
			}
			else {
				reloadCoolDown = reloadSpeed;
				currentMagazine = ammo;
				ammo -= currentMagazine;
			}
			std::cout
				<< "Ammo left: " << ammo << "\n";
		}	
	}	
}

float Gun::getAmmo(){
	if (reloadCoolDown <= 0 ){
		return (100 * (static_cast<float>(currentMagazine) / static_cast<float>(magazineSize)));
	} else {
		return 0;
	}
}

void Gun::setAmmo(int amount){
	amount = amount * magazineSize;
	ammo += amount;
}

void Gun::upgradeDmg(int amount){
	damage += amount;
}

void Gun::upgradeFireRate(short amount){
	fireRate -= amount;
}

void Gun::doubleDamage(){
	doubleDamageEnabled = true;
	doubleDamageTimer = 360;
}

int Gun::getDamageLevel() {
	return damageLevel;
}

void Gun::upgradeDamage() {
	if (damageLevel < 5){
		damage *= 1.10f;
		damageLevel++;
	}
}

int Gun::getFirerateLevel() {
	return fireRateLevel;
}

void Gun::upgradeFireRate() {
	if (fireRateLevel < 5){
		fireRate /= 1.10f;
		fireRateLevel++;
	}
}

int Gun::getReloadSpeedLevel() {
	return reloadSpeedLevel;
}

void Gun::upgradeReloadSpeed() {
	if (reloadSpeedLevel < 5){
		reloadSpeed /= 1.10f;
		reloadSpeedLevel++;
	}
}

std::string Gun::getInfo() {
	std::string info;
	info += "Name: " + name + "\n";
	info += "Damage: " + std::to_string(static_cast<int>(damage)) + "\n";
	info += "MagazineSize: " + std::to_string(magazineSize) + "\n";
	info += "BulletSpeed: " + std::to_string(bulletSpeed) + "\n";
	info += "FireRate: " + std::to_string(static_cast<int>(fireRate)) + "\n";
	info += "ReloadSpeed: " + std::to_string(static_cast<int>(reloadSpeed)) + "\n";
	return info;
}

void Gun::reset(){
	for (reloadSpeedLevel; reloadSpeedLevel >= 0; reloadSpeedLevel--){
		reloadSpeed *= 1.10f;
	}
	for (fireRateLevel; fireRateLevel > 0; fireRateLevel--){
		fireRate *= 1.10f;
	}
	for (damageLevel; damageLevel > 0; damageLevel--){
		damage /= 1.10f;
	}
}

void Gun::resetAmmo(){
	ammo = startAmmo;
	currentMagazine = magazineSize;
}

Gun::~Gun()
{
}