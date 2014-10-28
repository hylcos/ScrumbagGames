//! The Bullet header file
/*!
This is the header file of the circle class.
*/
#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Circle :
	public GameObject
{
public:
	//! The constructor of the circle
	/*!
	The constructor of the circle initializes the circle and assigns a color to it.
	*/
	Circle();

	//! The draw function of the circle
	/*!
	The draw function places the initialized circle on the screen.
	\param window The window in which the circle has to be drawn.
	*/
	void Circle::draw(sf::RenderWindow & window) const override;

	//! The deconstructor of the circle
	/*!
	Deallocates the circle.
	*/
	~Circle();

private:
	sf::CircleShape circle;
	const float circleSize = 5;
	const sf::Color circleColor = sf::Color::Red;
};
