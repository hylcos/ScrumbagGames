#pragma once
//#include "LevelController.h"
class GameController
{
public:
	GameController();
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
	void step();
	bool stopping = false;
};

