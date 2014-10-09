#pragma once
#include <SFML\Graphics.hpp>

class HudController
{
public:
	HudController();

	void HudController::step(sf::RenderWindow & window);

	~HudController();
};

