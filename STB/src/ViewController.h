#pragma once
#include <SFML/Graphics.hpp>
class ViewController
{
public:
	//getInstance returns the instance of ViewController. Used to call most functions.
	//
	//getInstance is used to return the instance of ViewController. This is used to prevent multiple instances of this controller to be made. 
	//@return ViewController instance;
	static ViewController& getInstance()
	{
		static ViewController    instance;
		return instance;
	}

	//startThread, used to start the thread of the ViewController.
	//
	//startThread starts the thread the ViewController uses to draw everything.
	void ViewController::startThread();

	//run, do not call!
	//
	//run is the function that actually does everything the ViewController has to do. Do not call this, instead use startThread()!
	void ViewController::run();
private:
	//Singleton creation
	ViewController() {}
	ViewController(ViewController const&); // Don't Implement.
	void operator=(ViewController const&); // Don't implement.

	void ViewController::step(sf::RenderWindow & window);
};

