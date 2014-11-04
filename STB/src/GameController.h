//! The gamecontroller header file
/*!
This is the header file of the gamecontroller class.
*/
#pragma once
#include "SoundController.h"
#include <SFML/Graphics.hpp>
#include "gameObjects/GameObject.h"
#include "LevelController.h"
#include "HudController.h"

//#define DEBUG

class LevelController;

class GameController
{
public:

	//!The getInstance method of the gamecontroller
	/*!
	This method makes sure there is only 1 instance of the gamecontroller at a time.
	This way, every time an external class uses a gamecontroller, it uses a gamecontroller
	with the same attributes as every other class.
	@return The instance of the gamecontroller
	*/
	static GameController& getInstance()
	{
		static GameController instance;
		return instance;
	}

	//! The getFPS method of the gamecontroller
	/*!
	@return The frames per second of the game
	*/
	float GameController::getFPS();

	//! The start method of the gamecontroller
	/*!
	Calling this method will cause the game to start running.
	*/
	void GameController::start();

	//! The stop method of the gamecontroller
	/*!
	Calling this method will stop the game.
	Prerequirement: the game has to be started.
	*/
	void GameController::stop();

	//! The getwindow method of the gamecontroller
	/*!
	@return The current window the game has to be drawn in
	*/
	sf::RenderWindow& GameController::getWindow();

	sf::Font * GameController::getFont();

	//! The deconstructor of the gamecontroller
	/*
	Deallocates the gamecontroller.
	*/
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
	sf::Font * font = nullptr;
	bool particlesEnabled;

	void step();
	bool stopping = false;
};

