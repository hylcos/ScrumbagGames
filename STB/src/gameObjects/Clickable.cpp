#include "../stdafx.h"
#include "Clickable.h"
#include "../LevelController.h"
#include <iostream>


Clickable::Clickable()
{
}

void Clickable::update(){
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return;
	}
	sf::Vector2f pos = LevelController::getInstance().getMousePos();
	std::cout << "Click at " << pos.x << '|' << pos.y <<"\n";
	if (getBounds().contains(pos)){
		click();
		std::cout << "Click\n";
	}
}

void Clickable::click(){

}

Clickable::~Clickable()
{
}
