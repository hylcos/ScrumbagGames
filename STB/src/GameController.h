#pragma once
#include "SoundController.h"
#include <SFML/Graphics.hpp>
class GameController
{
public:
	GameController(SoundController & soundController);
	//start (run) the game
	//
	//Call this function to start running the game.
	//@returns the exit code.
	void GameController::start();

	//stop the game
	//
	//This function will stop the game. Prerequirement: start() must be called.
	void GameController::stop();

	~GameController();

private:
	sf::RenderWindow window{ sf::VideoMode{640,480} ,"STB"};
	void checkWindow();

	SoundController & soundController;
	void step();
	bool stopping = false;
};

