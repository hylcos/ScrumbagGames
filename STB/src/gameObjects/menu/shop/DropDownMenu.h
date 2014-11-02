#pragma once
#include "../../Clickable.h"
class DropDownMenu : public Clickable
{
public:
	DropDownMenu();
	void DropDownMenu::update(float speedModifier) override;
	void DropDownMenu::draw(sf::RenderWindow & window) const override;
	void DropDownMenu::click() override;
	sf::FloatRect DropDownMenu::getBounds() override;
	~DropDownMenu();
private:
	std::vector<GameObject *> weapons;
	sf::Texture tex;
	sf::Sprite sprite;
	bool isClicked;
};

