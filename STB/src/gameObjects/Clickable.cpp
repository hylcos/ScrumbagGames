#include "../stdafx.h"
#include "Clickable.h"
#include "../LevelController.h"
#include <iostream>


Clickable::Clickable()
{
}

void Clickable::setOnHud(bool onHud){
	this->onHud = onHud;
}

void Clickable::update(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		lmbDown = true;
		return;
	}
	if (!lmbDown){
		return;
	}
	lmbDown = false;
	sf::Vector2f pos = (onHud?HudController::getInstance().getMousePos():LevelController::getInstance().getMousePos());
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
