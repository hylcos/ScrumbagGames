#include "..\stdafx.h"
#include "Logo.h"
#include <SFML\Graphics.hpp>
#include "../LevelController.h"


Logo::Logo()
{
	Logo::texture.loadFromFile("Resources/Images/Logo.png");
	Logo::logo.setTexture(texture, true);
	logo.setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().y / 2);
	logo.setPosition(320, 240);
}

void Logo::draw(sf::RenderWindow & window) const{
	window.draw(Logo::logo);
}

Logo::~Logo()
{
}
