#pragma once
#include <SFML/Graphics.hpp>
class ViewController
{
public:
	//Singleton creation
	static ViewController& getInstance()
	{
		static ViewController    instance;
		return instance;
	}

	void ViewController::startThread();
	void ViewController::run();
private:
	//Singleton creation
	ViewController() {}
	ViewController(ViewController const&); // Don't Implement.
	void operator=(ViewController const&); // Don't implement
};

