#pragma once
#include "SoundController.h"
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
	SoundController & soundController;
	void step();
	bool stopping = false;
};

