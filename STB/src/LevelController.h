#pragma once
#include "GameController.h"
#include "LevelController.h"
#include "Factory.h"
class GameController;
class LevelController
{
public:
	LevelController();

	class Initializer{
	public:
		Initializer(char randomness,std::string name);
		std::string name;
	private:
		char randomness;
	};

	void LevelController::startLevel(LevelController::Initializer initializer, GameController & gameController);

	LevelController::Initializer LEVEL_ONE{ (char)100, "Levels/init.level" };

	~LevelController();

private:
	//Factory factory;
};