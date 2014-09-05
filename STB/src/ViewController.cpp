#include "stdafx.h"
#include "ViewController.h"
#include <SFML/Graphics.hpp>
#include <process.h>
#include "GameController.h"

void ViewController::run(){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "STB" };
	puts("Window opened\nViewController started");

	sf::Event event;
	while (window.isOpen()){
		step(window);
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
				puts("Window closed");
				GameController::getInstance().stop();
				break;
			}
		}
		sf::sleep(sf::milliseconds(20));
	}
}

void ViewController::step(sf::RenderWindow & window){
	window.clear();
	window.display();
}

void runThreadViewController(void *){
	ViewController::getInstance().run();
}

void ViewController::startThread(){
	_beginthread(runThreadViewController, 0, (void*)0);
}