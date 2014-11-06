#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class Tutorial :
	public Clickable
{
public:
	Tutorial();

	void Tutorial::update(float speedModifier) override;
	void Tutorial::draw(sf::RenderWindow & window) const override;
	void Tutorial::click() override;
	sf::FloatRect Tutorial::getBounds() override;

	~Tutorial();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

