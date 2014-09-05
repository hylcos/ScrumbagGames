// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "ViewController.h"
#include "GameController.h"

int main()
{
	ViewController::getInstance().startThread();

	return GameController::getInstance().start();
}