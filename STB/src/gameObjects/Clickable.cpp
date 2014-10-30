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
		if (!lmbDown){
			sf::Vector2f pos = (onHud ? HudController::getInstance().getMousePos() : LevelController::getInstance().getMousePos());
			if (getBounds().contains(pos)){
				press();
			}
		}
		lmbDown = true;
		return;
	}
	if (!lmbDown){
		return;
	}
	lmbDown = false;
	release();

	sf::Vector2f pos = (onHud?HudController::getInstance().getMousePos():LevelController::getInstance().getMousePos());
	if (getBounds().contains(pos)){
		click();
	}
}

void Clickable::click(){

}

void Clickable::press(){

}

void Clickable::release(){

}

Clickable::~Clickable()
{
}
