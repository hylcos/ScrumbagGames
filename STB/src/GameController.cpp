#include "stdafx.h"
#include "GameController.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameObjects/GameObject.h"
#include "Level.h"
#include "gameObjects/Circle.h"

GameController::GameController(SoundController & soundController, Level & level) :
soundController{ soundController },
level{level}
{}

void GameController::stop(){
	stopping = true;
}

void GameController::addObject(GameObject * object){
	gameObjects.push_back(object);
}

void GameController::removeObject(GameObject * object){
	if (object == nullptr){
		return;
	}
	delete object;
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}

void GameController::start(){
	soundController.playMusic(soundController.INTRO);
	level.startLevel(level.LEVEL_ONE, this);
	while (!stopping){
		step();
	}
}

void GameController::step(){
	checkWindow();

	GameObject* last = nullptr;
	for (GameObject* obj : gameObjects){
		last = obj;
	}

	removeObject(last);

	addObject(new Circle());

	float speedModifier = 60 / fps;

	for (GameObject* obj : gameObjects){
		obj->update(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->move(speedModifier);
	}

	window.clear(sf::Color::White);

	for (GameObject* obj : gameObjects){
		obj->draw(window);
	}

	window.display();

	frames++;

	if (clock() > nextClock){
		nextClock = clock() + CLOCKS_PER_SEC/10;
		fps = fps / 10 * 9 + (float)frames;
		std::cout << fps << "\n";
		frames = 0;
	}
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
	for (GameObject* obj : gameObjects){
		obj->~GameObject();
	}
};