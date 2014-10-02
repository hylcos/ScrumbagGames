#pragma once
#include "GameController.h"
#include "Factory.h"
#include "gameObjects\Player.h"
#include <SFML\Graphics.hpp>

#define PI 3.14159265
class GameController;
class LevelController
{
public:
	static LevelController& getInstance()
	{
		static LevelController    instance;
		instance.load();
		return instance;
	}

	class Initializer{
	public:
		Initializer(std::string name);
		std::string name;
	};

	void LevelController::startLevel(LevelController::Initializer initializer);

	LevelController::Initializer LEVEL_ONE{ "Resources/Levels/init.level" };

	//add GameObject
	//
	//This function will put a new GameObject under the control of the GameController.
	void LevelController::addObject(GameObject * object);

	//remove GameObject
	//
	//This function will remove a GameObject under the control of the GameController, and DESTROY the GameObject in question.
	void LevelController::removeObject(GameObject * object);

	//Move the main view
	void LevelController::moveMainView(float x, float y);

	//Set the main view position
	void LevelController::setMainView(float x, float y);

	void LevelController::step(float fps, sf::RenderWindow & window);

	Player * LevelController::getPlayer();

private:
	LevelController() {};
	LevelController(LevelController const&);
	void operator=(LevelController const&);

	void LevelController::load();
	bool isLoaded = false;

	sf::View mainView;

	sf::Texture background;
	sf::Texture backgroundOverlay;

	sf::Sprite backgroundSprite;
	sf::Sprite backgroundSpriteOverlay;

	sf::Uint8 terrorLevel = 255;

	std::vector< GameObject* > gameObjects;

	Player * player = nullptr;
};