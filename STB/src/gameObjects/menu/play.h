#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class Play :
	public Clickable
{
public:
	Play();

	void Play::update(float speedModifier) override;
	void Play::draw(sf::RenderWindow & window) const override;
	void Play::click() override;
	sf::FloatRect Play::getBounds() override;

	~Play();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};