// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "SoundController.h"
#include <Windows.h>
#include "Level.h"

int main()
{
#ifndef DEBUG//Defined in GameController.h
	ShowWindow(GetConsoleWindow(), SW_HIDE); // Hide the console
#endif

	Level level;
	SoundController soundController;
	GameController gameController{ soundController, level };

	gameController.start();
	return 0;
}