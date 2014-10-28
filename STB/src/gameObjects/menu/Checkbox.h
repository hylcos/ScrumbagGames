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
	sf::FloatRect Checkbox::getBounds() override;

	~Checkbox();
protected:
	bool checked = false;
	virtual void Checkbox::toggle(bool checked);
	sf::Text text;
private:
	sf::Texture * texChecked, *texUnchecked;
	sf::Sprite sprite;
};

