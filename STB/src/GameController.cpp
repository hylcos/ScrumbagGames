#include "stdafx.h"
#include "GameController.h"
#include "SoundController.h"
#include <SFML/Graphics.hpp>
#include "gameObjects/GameObject.h"
#include "LevelController.h"
#include "TextureManager.h"

#ifdef DEBUG//Defined in GameController.h
#include <iostream>
#endif

void GameController::stop(){
	stopping = true;
}

void GameController::start(){
	SoundController::getInstance().load();
	LevelController::getInstance().startLevel(LevelController::getInstance().MENU_MAIN);
	changeCursor();
	while (!stopping){
		step();
	}
}

float GameController::getFPS(){
	return fps;
}

sf::RenderWindow& GameController::getWindow(){
	return window;
}

void GameController::changeCursor(){
	sf::View fixed = window.getView();
	window.setMouseCursorVisible(false);
	window.setView(fixed);
	cursortex = *TextureManager::getInstance().getTexture("Sprites/Crosshair.png");
	cursorsprite.setOrigin(cursortex.getSize().x / 2.0f, cursortex.getSize().y/2.0f);
	cursorsprite.setTexture(cursortex);
	cursorsprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	window.draw(cursorsprite);
}

void GameController::step(){
	checkWindow();
	LevelController::getInstance().step(fps, window);
	HudController::getInstance().step(window);
	cursorsprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	window.draw(cursorsprite);
	window.display();
	
	
	frames++;

	if (clock() > nextClock){
		nextClock = clock() + CLOCKS_PER_SEC / 30;
		//fps = fps / 3 * 2 + (float)frames;
		fps = 30.f * frames;
#ifdef DEBUG//Defined in GameController.h
		std::cout << fps << "\n";
#endif

		frames = 0;
	}
}

sf::Font * GameController::getFont(){
	if (font == nullptr){
		font = new sf::Font();
		font->loadFromFile("Resources/Fonts/Coalition_v2.ttf");
	}
	return font;
}

void GameController::checkWindow(){
	sf::Event event;

	if (!window.isOpen()){
		stop();
		return;
	}
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed){
			stop();
			return;
		}
		
		
	}
	


}

GameController::~GameController(){
};