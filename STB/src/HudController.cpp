#include "stdafx.h"
#include "HudController.h"
#include "LevelController.h"

HudController::HudController()
{
}

void HudController::step(sf::RenderWindow & window){
	sf::View hudView;
	hudView.setCenter(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	hudView.setSize(static_cast<sf::Vector2f>(window.getSize()));
	//hudView.setCenter(sf::Vector2f(0.0f, 0.0f));
	window.setView(hudView);

	sf::RectangleShape rect(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	rect.setFillColor(sf::Color::Black);
	rect.setOrigin(rect.getSize()/2.0f);
	rect.setPosition(hudView.getSize() / 2.0f);

	window.draw(rect);
}

HudController::~HudController()
{
}
