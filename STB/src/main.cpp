// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "SoundController.h"
#include <Windows.h>
#include "LevelController.h"

int main()
{
#ifndef DEBUG//Defined in GameController.h
	ShowWindow(GetConsoleWindow(), SW_HIDE); // Hide the console
#endif

	LevelController levelController;
	SoundController soundController;
	GameController gameController{ soundController, levelController };

	gameController.start();
	return 0;
}