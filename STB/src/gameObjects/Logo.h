#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Logo :
	public GameObject
{
public:
	Logo();

	void Logo::update(float speedModifier) override;
	void Logo::draw(sf::RenderWindow & window) const override;

	~Logo();
private:
	float time;
	sf::Texture Logo::texture;
	sf::Sprite Logo::logo;
};

