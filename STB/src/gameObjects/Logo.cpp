#include "..\stdafx.h"
#include "Logo.h"
#include <SFML\Graphics.hpp>
#include "../LevelController.h"

Logo::Logo()
{
	Logo::texture.loadFromFile("Resources/Images/Logo.png");
	Logo::logo.setTexture(texture, true);
	Logo::logo.setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().y / 2);
	Logo::logo.setPosition(640, 480);
	time = 300;
}

void Logo::update(float speedModifier){
	Logo::logo.setPosition(position);
	time -= speedModifier;
	if (time <= 0){
		LevelController::getInstance().goToNextLevel(&LevelController::getInstance().MENU_MAIN);
	}
}

void Logo::draw(sf::RenderWindow & window) const{
	window.draw(Logo::logo);
}

Logo::~Logo()
{
}
