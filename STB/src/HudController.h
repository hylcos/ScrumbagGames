#pragma once
#include <SFML\Graphics.hpp>

class HudController
{
public:
	static HudController& getInstance()
	{
		static HudController    instance;
		instance.load();
		return instance;
	}

	void HudController::load();

	void HudController::step(sf::RenderWindow & window);

	~HudController(){};
private:
	HudController() {};
	HudController(HudController const&);
	void operator=(HudController const&);

	bool isLoaded = false;

	sf::RectangleShape HPBackGround, HPForeGround;
	sf::RectangleShape ammoBackGround, ammoForeGround;
	sf::RectangleShape background;
};

