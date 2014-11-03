#pragma once
#include "../../Clickable.h"
#include "../../Weapon.h"
class Upgrade : public Clickable
{
public:
	enum types{
		FireRate,
		Damage,
		ReloadSpeed
	};
	Upgrade(Weapon * weapon,types type);
	void Upgrade::update(float speedModifier) override;
	void Upgrade::draw(sf::RenderWindow & window) const override;
	void Upgrade::click() override;
	sf::FloatRect Upgrade::getBounds() override;
	void Upgrade::updateWeapon(Weapon * weapon);
	~Upgrade();
private:
	sf::RectangleShape backGround[5];
	sf::RectangleShape foreGround[5];
	sf::Text text;
	types type;
	sf::Sprite sprite;
	sf::Texture tex;
	int UpgradeLevel;
	Weapon * weapon;
};

