#include "stdafx.h"
#include "ViewController.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <process.h>
#include "GameController.h"

void runThread(void *){
	ViewController::getInstance().run();
}

void ViewController::run(){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "STB" };

	sf::Event event;
	window.clear();
	window.display();
	while (window.isOpen()){
		while (window.pollEvent(event)){
			puts("Event");
			if (event.type == sf::Event::Closed){
				window.close();
				puts("Stopping");
				GameController::getInstance().stop();
				break;
			}
		}
		sf::sleep(sf::milliseconds(20));
	}
}

void ViewController::startThread(){
	_beginthread(runThread, 0, (void*)0);
}