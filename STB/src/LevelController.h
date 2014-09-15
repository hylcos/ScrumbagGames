#pragma once
#include "GameController.h"
class GameController;
class LevelController
{
public:
	LevelController();

	class Initializer{
	public:
		Initializer(char randomness);
	private:
		char randomness;
	};

	void LevelController::startLevel(LevelController::Initializer initializer, GameController * gameController);

	LevelController::Initializer LEVEL_ONE{ (char)100 };

	~LevelController();

private:
};

