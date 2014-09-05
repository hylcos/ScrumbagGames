// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "ViewController.h"
#include "GameController.h"


static bool stop = false;

int main()
{
	ViewController::getInstance().startThread();

	GameController::getInstance().start();
	return 0;
}

void endGame(){
	stop = true;
}