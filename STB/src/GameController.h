#pragma once
#include "SoundController.h"
#include <SFML/Graphics.hpp>
#include "gameObjects/GameObject.h"
#include "LevelController.h"

#define DEBUG

class LevelController;

class GameController
{
public:
	GameController(SoundController & soundController, LevelController & levelController);
	//start (run) the game
	//
	//Call this function to start running the game.
	//@returns the exit code.
	void GameController::start();

	//stop the game
	//
	//This function will stop the game. Prerequirement: start() must be called.
	void GameController::stop();

	//add GameObject
	//
	//This function will put a new GameObject under the control of the GameController.
	void GameController::addObject(GameObject * object);

	//remove GameObject
	//
	//This function will remove a GameObject under the control of the GameController, and DESTROY the GameObject in question.
	void GameController::removeObject(GameObject * object);

	~GameController();

private:
	sf::RenderWindow window{ sf::VideoMode{640,480} ,"STB"};
	void checkWindow();

	std::vector< GameObject* > gameObjects;

	float fps = 5000.0f;
	int frames = 0;
	clock_t nextClock;

	SoundController & soundController;
	LevelController & levelController;

	void step();
	bool stopping = false;
};

