#include "../../../stdafx.h"
#include "switchWeapon.h"
#include "../../../TextureManager.h"
#include < iostream > 

switchWeapon::switchWeapon()
{
	tex = *TextureManager::getInstance().getTexture("menuObjecten/SwitchWeaponButton.png");
	sprite.setTexture(tex);
}
void switchWeapon::update(float speedModifier) {

	sprite.setPosition(position);
	Clickable::update();
}
void switchWeapon::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
void switchWeapon::click() {
	clicked = true;
}
sf::FloatRect switchWeapon::getBounds() {
	return sprite.getGlobalBounds();
}

bool switchWeapon::isClicked(){
	if (clicked){
		std::cout << "Switch! \n";
		clicked = false;
		return true;
	}
	return false;
}
switchWeapon::~switchWeapon()
{
}
