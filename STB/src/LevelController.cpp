#include "stdafx.h"
#include "GameController.h"
#include "LevelController.h"
#include "Factory.h"

#include <SFML\Graphics.hpp>

LevelController::LevelController()
{
	background.loadFromFile("Resources/Images/Background.jpg");
	backgroundOverlay.loadFromFile("Resources/Images/BackgroundOverlay.jpg");

	backgroundSprite.setTexture(background,true);
	backgroundSpriteOverlay.setTexture(backgroundOverlay,true);

	mainView.setSize(sf::Vector2f(640, 480));
	mainView.setCenter(320,240);
}

LevelController::Initializer::Initializer(char randomness, std::string name) :
randomness{ randomness }
{
	Initializer::name = name;
}

void LevelController::startLevel(LevelController::Initializer initializer){
	Factory factory;
	factory.loadLevel(initializer.name, *this);
}

void LevelController::step(float fps, sf::RenderWindow & window){
	float speedModifier = 60 / fps;

	for (GameObject* obj : gameObjects){
		obj->update(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->move(speedModifier);
	}

	window.clear(sf::Color::White);

	window.draw(backgroundSprite);
	backgroundSpriteOverlay.setColor(sf::Color{ 255, 255, 255, terrorLevel });
	window.draw(backgroundSpriteOverlay);

	window.setView(mainView);
	moveMainView(0.64f*speedModifier,0.48f*speedModifier);

	for (GameObject* obj : gameObjects){
		obj->draw(window);
	}

	window.display();
}

void LevelController::moveMainView(float x, float y){
	setMainView(mainView.getCenter().x + x, mainView.getCenter().y + y);
}

void LevelController::setMainView(float x, float y){
	mainView.setCenter(std::min(std::max(x, 320.0f), 1280.0f - 320.0f), std::min(std::max(y, 240.0f), 960.0f - 240.0f));
}

void LevelController::addObject(GameObject * object){
	gameObjects.push_back(object);
}

void LevelController::removeObject(GameObject * object){
	if (object == nullptr){
		return;
	}
	delete object;
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}


LevelController::~LevelController()
{
	for (GameObject* obj : gameObjects){
		obj->~GameObject();
	}
}
