// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "ViewController.h"
#include "GameController.h"
#include "SoundController.h"
#include "UpdateController.h"
#include "LevelController.h"
#include "InputController.h"

int main()
{
	ViewController::getInstance().startThread();
	SoundController::getInstance().startThread();
	UpdateController::getInstance().startThread();
	LevelController::getInstance().startThread();
	InputController::getInstance().startThread();

	return GameController::getInstance().start();
}