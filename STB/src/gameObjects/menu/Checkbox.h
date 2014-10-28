#pragma once
#include "..\Clickable.h"
class Checkbox :
	public Clickable
{
public:
	Checkbox();
	void Checkbox::update(float speedModifier) override;
	void Checkbox::draw(sf::RenderWindow & window) const override;
	void Checkbox::click() override;
	void Checkbox::setToggleAction(void(*function)(bool checked));
	sf::FloatRect Checkbox::getBounds() override;

	~Checkbox();
private:
	bool checked = false;
	void (*function)(bool checked) = nullptr;
	sf::Texture * texChecked, *texUnchecked;
	sf::Sprite sprite;
};

