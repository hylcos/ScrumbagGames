#pragma once
#include "SoundController.h"
#include <SFML/Graphics.hpp>
#include "gameObjects/GameObject.h"
#include "LevelController.h"
#include "HudController.h"

#define DEBUG

class LevelController;

class GameController
{
public:

	static GameController& getInstance()
	{
		static GameController    instance;
		return instance;
	}

	float GameController::getFPS();

	//start (run) the game
	//
	//Call this function to start running the game.
	//@returns the exit code.
	void GameController::start();

	//stop the game
	//
	//This function will stop the game. Prerequirement: start() must be called.
	void GameController::stop();

	sf::RenderWindow& GameController::getWindow();

	~GameController();

private:
	GameController(){};
	GameController(GameController const&) = delete;
	void operator=(GameController const&) = delete;
	void GameController::changeCursor();
	sf::RenderWindow window{ sf::VideoMode(640, 480), "STB", sf::Style::Titlebar | sf::Style::Close };
	void checkWindow();
	sf::Sprite cursorsprite;
	sf::Texture cursortex;
	float fps = 100.0f;
	int frames = 0;
	clock_t nextClock;

	void step();
	bool stopping = false;
};

