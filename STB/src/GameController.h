#pragma once
class GameController
{
public:
	//Singleton creation
	static GameController& getInstance()
	{
		static GameController    instance;
		return instance;
	}

	//start (run) the game
	//
	//Call this function to start running the game.
	//@returns the exit code.
	int GameController::start();

	//stop the game
	//
	//This function will stop the game. Prerequirement: start() must be called.
	void GameController::stop();

	//check if the game is running
	//
	//This function is used to check if the game is running.
	//@return bool running
	bool GameController::isRunning();

private:
	//Singleton creation
	GameController() {}
	GameController(GameController const&); // Don't Implement.
	void operator=(GameController const&); // Don't implement
	bool stopping = false;
};

