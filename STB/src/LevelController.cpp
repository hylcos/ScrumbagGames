#include "stdafx.h"
#include "GameController.h"
#include "LevelController.h"
#include "Factory.h"
#include "GameObjects/Powerup.h"
#include <SFML\Graphics.hpp>

void LevelController::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;
	background.loadFromFile("Resources/Images/Background.jpg");
	backgroundOverlay.loadFromFile("Resources/Images/BackgroundOverlay.jpg");

	backgroundSprite.setTexture(background, true);
	backgroundSpriteOverlay.setTexture(backgroundOverlay, true);

	mainView.setSize(sf::Vector2f(640, 480));
	mainView.setCenter(320, 240);
}

LevelController::Initializer::Initializer(std::string name)
{
	Initializer::name = name;
}

void LevelController::startLevel(LevelController::Initializer initializer){
	Factory factory;
	int settings = factory.loadLevel(initializer.name);
	terrorLevel = settings & 255;
	bool random = ((settings & factory.random) == factory.random);
	player = nullptr;
	for (GameObject* obj : gameObjects){
		if (random){
			obj->setRandomness(terrorLevel);
		}
		Player* v = dynamic_cast<Player*>(obj);
		if (v != 0) {
			player = v;
		}
	}
	addObjectFromFactory(new Powerup(sf::Vector2f{ 250, 250 },6));

	addObjectFromFactory(new Powerup(sf::Vector2f{ 200, 250 }, 0));

	addObjectFromFactory(new Powerup(sf::Vector2f{ 150, 250 }, 4));

	addObjectFromFactory(new Powerup(sf::Vector2f{ 100, 250 }, 3));


}

void LevelController::step(float fps, sf::RenderWindow & window){
	float speedModifier = 60 / fps;
	for (GameObject* obj : gameObjectToAdd){
		gameObjects.push_back(obj);
	}
	gameObjectToAdd.clear();

	for (GameObject* obj : gameObjectToRemove){
		LevelController::removeAllObjects(obj);
	}
	gameObjectToRemove.clear();

	for (GameObject* obj : gameObjects){
		obj->update(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->move(speedModifier);
	}

	//window.clear(sf::Color::White);

	window.draw(backgroundSprite);
	backgroundSpriteOverlay.setColor(sf::Color{ 255, 255, 255, terrorLevel });
	window.draw(backgroundSpriteOverlay);

	window.setView(mainView);
	if (player != nullptr){
		setMainView(player->getPosition().x, player->getPosition().y);
		sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(window)) - sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f) + mainView.getCenter() - player->getPosition();
		player->setRotation(atan2(pos.y, pos.x) * 180 / 3.14159265358979323846f + 90);
	}

	for (GameObject* obj : gameObjects){
		obj->draw(window);
	}

	window.display();
}

const std::vector< GameObject* > LevelController::getGameObjects(){
	return gameObjects;
}

void LevelController::moveMainView(float x, float y){
	setMainView(mainView.getCenter().x + x, mainView.getCenter().y + y);
}

void LevelController::setMainView(float x, float y){
	mainView.setCenter(std::min(std::max(x, 320.0f), 1280.0f - 320.0f), std::min(std::max(y, 240.0f), 960.0f - 240.0f));
}

void LevelController::addObject(GameObject * object){
	gameObjectToAdd.push_back(object);
}
void LevelController::addObjectFromFactory(GameObject * object){
	gameObjects.push_back(object);
}
void LevelController::removeObject(GameObject * object){
	gameObjectToRemove.insert(object);
}
void LevelController::removeAllObjects(GameObject * object){
	if (object == nullptr){
		return;
	}
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	delete object;
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}

Player * LevelController::getPlayer(){
	return player;
}
/*
LevelController::~LevelController()
{
	for (GameObject* obj : gameObjects){
		obj->~GameObject();
	}
}*/
