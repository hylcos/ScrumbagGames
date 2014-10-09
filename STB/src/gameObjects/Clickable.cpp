#include "../stdafx.h"
#include "Clickable.h"
#include "../LevelController.h"


Clickable::Clickable()
{
}

void Clickable::update(){
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return;
	}
	sf::Vector2f pos = LevelController::getInstance().getMousePos();
	if (getBounds().contains(pos)){
	}
}

void Clickable::click(){

}

Clickable::~Clickable()
{
}
