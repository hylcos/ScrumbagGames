#include "stdafx.h"
#include "HudController.h"
#include "LevelController.h"
#include "TextureManager.h"

void HudController::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;
	HPBackGround.setFillColor(sf::Color::Black);
	HPBackGround.setSize(sf::Vector2f(100, 15));
	HPBackGround.setPosition(sf::Vector2f(60, 457.5));

	HPForeGround.setFillColor(sf::Color::Red);
	HPForeGround.setPosition(sf::Vector2f(60, 457.5));

	ammoBackGround.setFillColor(sf::Color::Black);
	ammoBackGround.setSize(sf::Vector2f(100, 15));
	ammoBackGround.setPosition(sf::Vector2f(300, 457.5));

	ammoForeGround.setFillColor(sf::Color::Yellow);
	ammoForeGround.setPosition(sf::Vector2f(300, 457.5));

	background.setFillColor(sf::Color::White);
	background.setSize(sf::Vector2f(140, 25));
	

}

void HudController::addObject(GameObject * object){
	gameObjectToAdd.push_back(object);
}
void HudController::addObjectFromFactory(GameObject * object){
	gameObjects.push_back(object);
}
void HudController::removeObject(GameObject * object){
	gameObjectToRemove.insert(object);
}
void HudController::removeAllObjects(GameObject * object){
	if (object == nullptr){
		return;
	}
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	delete object;
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}

void HudController::step(sf::RenderWindow & window){
	sf::View hudView;
	hudView.setCenter(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	hudView.setSize(static_cast<sf::Vector2f>(window.getSize()));
	//hudView.setCenter(sf::Vector2f(0.0f, 0.0f));
	window.setView(hudView);
	if (LevelController::getInstance().getPlayer() != nullptr){
		HPForeGround.setSize(sf::Vector2f(static_cast<float>(LevelController::getInstance().getPlayer()->getHp()), 15));
		ammoForeGround.setSize(sf::Vector2f(static_cast<float>(LevelController::getInstance().getPlayer()->getAmmo()), 15));
	}
	else {
		HPForeGround.setSize(sf::Vector2f(100, 15));
		ammoForeGround.setSize(sf::Vector2f(100, 15));
	}
	
	background.setPosition(sf::Vector2f(40, 455));
	window.draw(background);
	background.setPosition(sf::Vector2f(280, 455));
	window.draw(background);
	window.draw(HPBackGround);
	window.draw(HPForeGround);
	window.draw(ammoBackGround);
	window.draw(ammoForeGround);
}
