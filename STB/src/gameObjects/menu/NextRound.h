#pragma once
#include "..\Clickable.h"
#include <SFML\Graphics.hpp>

class NextRound :
	public Clickable
{
public:
	NextRound();

	void NextRound::update(float speedModifier) override;
	void NextRound::draw(sf::RenderWindow & window) const override;
	void NextRound::click() override;
	sf::FloatRect NextRound::getBounds() override;

	~NextRound();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

