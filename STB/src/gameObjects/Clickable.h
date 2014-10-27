#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class Clickable : public GameObject
{
public:
	Clickable();

	void setOnHud(bool onHud);
	void Clickable::update();
	virtual void Clickable::click();


	~Clickable();
private:
	bool onHud = false;
};

