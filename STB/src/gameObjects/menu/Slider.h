#pragma once
#include "..\Clickable.h"
class Slider :
	public Clickable
{
public:
	Slider();
	void Slider::draw(sf::RenderWindow & window) const override;
	void Slider::release() override;
	void Slider::press() override;
	void Slider::update(float speedModifier) override;
	virtual void Slider::updateValue(int value);
	sf::FloatRect Slider::getBounds() override;
	~Slider();
protected:
	int value;
private:
	bool selected = false;
	sf::Sprite spriteScrollButton, spriteScrollBar;
};

