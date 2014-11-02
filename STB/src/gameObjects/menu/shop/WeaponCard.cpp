#include "../../../stdafx.h"
#include "WeaponCard.h"
#include "../../../TextureManager.h"
#include "../../../HudController.h"
#include "../../../GameController.h"
WeaponCard::WeaponCard()
{
}

WeaponCard::WeaponCard(Weapon * weapon):
weapon{ weapon }
{
	backgroundTexture = *TextureManager::getInstance().getTexture("menuObjecten/WeaponCardBackGround.png");
	backgroundSprite.setTexture(backgroundTexture);

	weaponTexture = *TextureManager::getInstance().getTexture("HUDObjecten/"+ weapon->getName() + "Weapon.png");
	weaponSprite.setTexture(weaponTexture);

	fireSpeedUpgrade = new Upgrade(weapon, "FireRate");
	fireSpeedUpgrade->setOnHud(true);
	HudController::getInstance().addObject(fireSpeedUpgrade);

	damageUpgrade = new Upgrade(weapon,"Damage");
	damageUpgrade->setOnHud(true);
	HudController::getInstance().addObject(damageUpgrade);

	weaponInfo.setFont(*GameController::getInstance().getFont());
	weaponInfo.setCharacterSize(10);
	weaponInfo.setColor(sf::Color(255, 20, 20));
	weaponInfo.setPosition(position);
	weaponInfo.setString(weapon->getInfo());
}

void WeaponCard::update(float speedModifier) {

	backgroundSprite.setPosition(position);
	weaponInfo.setPosition(sf::Vector2f(position.x+16, position.y + 280));
	weaponInfo.setString(weapon->getInfo());
	damageUpgrade->setPosition(sf::Vector2f(position.x + 40, position.y + 180));
	fireSpeedUpgrade->setPosition(sf::Vector2f(position.x + 40, position.y + 80));
	weaponSprite.setPosition(sf::Vector2f(position.x + 40, position.y + 40));

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

WeaponCard::~WeaponCard()
{
}
