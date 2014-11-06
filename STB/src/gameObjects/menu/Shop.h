#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class Shop :
	public Clickable
{
public:
	Shop();

	void Shop::update(float speedModifier) override;
	void Shop::draw(sf::RenderWindow & window) const override;
	void Shop::click() override;
	sf::FloatRect Shop::getBounds() override;

	~Shop();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

