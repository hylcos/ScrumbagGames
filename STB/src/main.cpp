// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "SoundController.h"
#include <Windows.h>
#include "LevelController.h"
#include "HudController.h"

int main()
{
	srand((unsigned int)time(NULL));
#ifndef DEBUG//Defined in GameController.h
	ShowWindow(GetConsoleWindow(), SW_HIDE); // Hide the console
#endif

	LevelController::getInstance();
	SoundController soundController;
	HudController hudController;
	GameController gameController{ soundController, hudController };

	gameController.start();
	return 0;
}