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

	int GameController::start();
	void GameController::stop();
private:
	//Singleton creation
	GameController() {}
	GameController(GameController const&); // Don't Implement.
	void operator=(GameController const&); // Don't implement
	bool stopping = false;
};

