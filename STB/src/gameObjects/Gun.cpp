
#include "Gun.h"
#include "../LevelController.h"
Gun::Gun(std::string name, int damage, float reloadSpeed,int ammo, int magazineSize, int range, short bulletSpeed,short fireRate) :
damage{ damage },
reloadSpeed{ reloadSpeed },
magazineSize{ magazineSize },
range{ range },
bulletSpeed{ bulletSpeed },
fireRate{ fireRate },
ammo{ ammo }
{
	Gun::name = name;
	tex = *TextureManager::getInstance().getTexture(name + ".png");
	TextureManager::getInstance().getTexture(name + "_bullet.png");
	sprite.setTexture(tex);
	sprite.setOrigin(tex.getSize().x / 2.0f, tex.getSize().x*1.5f);
	ammo -= magazineSize;
	currentMagazine = magazineSize;
}

void Gun::fire(){
	if (ammo > 0){
		if (reloadCoolDown <= 0){
			if (shootCoolDown <= 0){
				Bullet * newBullet = new Bullet(name + "_bullet.png", rotation, bulletSpeed, damage*multipler, position);
				LevelController::getInstance().addObject(newBullet);
				shootCoolDown = fireRate;
				currentMagazine--;
				if (name != "Sprites/Weapons/pistol"){
					ammo--;
				}
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
void Gun::setRotation(float rotation){
	this->rotation = rotation;
}
void Gun::update(float speedModifier) {
	shootCoolDown -= speedModifier;
	reloadCoolDown -= speedModifier;
	sprite.setPosition(position);
	sprite.setRotation(rotation);
}
void Gun::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
void Gun::reload(){
	if (ammo!=0	){
		if (reloadCoolDown <= 0){
			if (magazineSize <= ammo){
				reloadCoolDown = reloadSpeed;
				if (currentMagazine > 0)
					ammo += currentMagazine;
				currentMagazine = magazineSize;
				if (name != "Sprites/Weapons/pistol"){
					ammo -= currentMagazine;
				}
			}
			std::cout
				<< "Ammo left: " << ammo << "\n";
		}
	}
}
Gun::~Gun()
{
}