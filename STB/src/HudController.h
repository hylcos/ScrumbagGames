#pragma once
#include <SFML\Graphics.hpp>

class HudController
{
public:
	HudController();

	void HudController::step(sf::RenderWindow & window);

	~HudController();
private:
	sf::RectangleShape HPBackGround, HPForeGround;
	sf::RectangleShape ammoBackGround, ammoForeGround;
	sf::RectangleShape background;
};

