#pragma once
#include "..\Clickable.h"
class Resume :
	public Clickable
{
public:
	Resume();
	void Resume::update(float speedModifier) override;
	void Resume::draw(sf::RenderWindow & window) const override;
	void Resume::click() override;
	sf::FloatRect Resume::getBounds() override;
	~Resume();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

