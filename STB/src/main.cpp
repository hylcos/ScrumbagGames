// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "SoundController.h"
#include "InputController.h"

int main()
{
	GameController gameController;

	SoundController soundController;
	soundController.playMusic();

	gameController.start();

	return 0;
}