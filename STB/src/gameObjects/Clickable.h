//! The Clickable header file
/*!
This is the header file of the clickable class.
*/
#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class Clickable : public GameObject
{
public:
	//! The constructor for the clickable class
	/*!
	The default constructor, doesn't do anything specifical.
	*/
	Clickable();

	//! The update method for the clickable class
	/*!
	checks if there has been a click, and if there was, checks if the click was on this specific game object.
	when the click is within the bounds of this game object, the click() method will be called
	*/
	void Clickable::update();


	void Clickable::setOnHud(bool onHud);

	//! The click method for the clickable class
	/*!
	In this method there will be specified what has to happen when this game object is clicked.
	*/

	//TODO: make virtual.
	virtual void Clickable::click();

	//! The deconstructor of the clickable class
	/*!
	Deallocates the clickable object.
	*/
	~Clickable();
private:
	bool onHud = false;
};

