#include "../../../stdafx.h"
#include "WeaponCard.h"
#include "../../../TextureManager.h"
#include "../../../HudController.h"
#include "../../../GameController.h"
#include "../../WeaponManager.h"
WeaponCard::WeaponCard()
{
}

WeaponCard::WeaponCard(Weapon * wpn):
weapon{ wpn }
{
	std::cout << weapon->getName() << "\n";
	backgroundTexture = *TextureManager::getInstance().getTexture("menuObjecten/WeaponCardBackGround.png");
	backgroundSprite.setTexture(backgroundTexture);

	weaponTexture = *TextureManager::getInstance().getTexture("HUDObjecten/"+ weapon->getName() + "Weapon.png");
	weaponSprite.setTexture(weaponTexture);

	switchButton = new switchWeapon();
	switchButton->setOnHud(true);
	HudController::getInstance().addObject(switchButton);
	std::cout << "SwitchButton Made";
	

	fireSpeedUpgrade = new Upgrade(weapon, "FireRate");
	fireSpeedUpgrade->setOnHud(true);
	HudController::getInstance().addObject(fireSpeedUpgrade);

	damageUpgrade = new Upgrade(weapon,"Damage");
	damageUpgrade->setOnHud(true);
	HudController::getInstance().addObject(damageUpgrade);

	reloadSpeed = new Upgrade(weapon, "ReloadSpeed");
	reloadSpeed->setOnHud(true);
	HudController::getInstance().addObject(reloadSpeed);

	weaponInfo.setFont(*GameController::getInstance().getFont());
	weaponInfo.setCharacterSize(10);
	weaponInfo.setColor(sf::Color(255, 20, 20));
	weaponInfo.setPosition(position);
	weaponInfo.setString(weapon->getInfo());
}

void WeaponCard::update(float speedModifier) {

	backgroundSprite.setPosition(position);
	weaponInfo.setPosition(sf::Vector2f(position.x+16, position.y + 300));
	
	damageUpgrade->setPosition(sf::Vector2f(position.x + 40, position.y + 140));
	fireSpeedUpgrade->setPosition(sf::Vector2f(position.x + 40, position.y + 80));
	reloadSpeed->setPosition(sf::Vector2f(position.x + 40, position.y + 200));
	switchButton->setPosition(sf::Vector2f(position.x + 40, position.y));
	weaponSprite.setPosition(sf::Vector2f(position.x + 40, position.y + 40));

	if (timeToUpdateInfo <= 0){
		timeToUpdateInfo = 1;
		weaponInfo.setString(weapon->getInfo());
	}
	else {
		timeToUpdateInfo -= speedModifier;
	}
	
	if (switchButton->isClicked()){
		changeWeapon();
	}

}
void WeaponCard::draw(sf::RenderWindow & window) const {
	window.draw(backgroundSprite);
	window.draw(weaponSprite);
	window.draw(weaponInfo);
}
Weapon * WeaponCard::getWeapon(){
	return weapon;
}

void WeaponCard::setWeapon(Weapon * weapon){
	this->weapon = weapon;
}

void WeaponCard::changeWeapon(){
	weapon = WeaponManager::getInstance().getOtherWeapon(weapon);
	weaponTexture = *TextureManager::getInstance().getTexture("HUDObjecten/" + weapon->getName() + "Weapon.png");
	weaponInfo.setString(weapon->getInfo());
	reloadSpeed->updateWeapon(weapon);
	fireSpeedUpgrade->updateWeapon(weapon);
	damageUpgrade->updateWeapon(weapon);
}
WeaponCard::~WeaponCard()
{
}
