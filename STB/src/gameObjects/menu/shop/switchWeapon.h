#pragma once
#include "../../Clickable.h"
class switchWeapon : public Clickable
{
public:
	switchWeapon();
	void switchWeapon::update(float speedModifier) override;
	void switchWeapon::draw(sf::RenderWindow & window) const override;
	void switchWeapon::click() override;
	bool switchWeapon::isClicked();
	sf::FloatRect switchWeapon::getBounds() override;

	~switchWeapon();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	bool clicked = false;
};

