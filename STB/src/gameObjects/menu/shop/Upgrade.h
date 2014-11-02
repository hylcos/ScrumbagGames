#pragma once
#include "../../Clickable.h"
#include "../../Weapon.h"
class Upgrade : public Clickable
{
public:
	Upgrade(Weapon * weapon,std::string type);
	void Upgrade::update(float speedModifier) override;
	void Upgrade::draw(sf::RenderWindow & window) const override;
	void Upgrade::click() override;
	sf::FloatRect Upgrade::getBounds() override;
	~Upgrade();
private:
	sf::RectangleShape backGround[5];
	sf::RectangleShape foreGround[5];
	sf::Text text;
	std::string type;
	sf::Sprite sprite;
	sf::Texture tex;
	int UpgradeLevel;
	Weapon * weapon;
};

