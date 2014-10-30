#pragma once
#include "..\Clickable.h"
class Slider :
	public Clickable
{
public:
	Slider();
	void Slider::draw(sf::RenderWindow & window) const override;
	~Slider();
private:
	int value;
	sf::Sprite spriteScrollButton, spriteScrollBar;
};

