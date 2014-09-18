#pragma once
#include "GameController.h"
#include "LevelController.h"
#include "Factory.h"

#include <SFML\Graphics.hpp>

class GameController;
class LevelController
{
public:
	LevelController();

	class Initializer{
	public:
		Initializer(char randomness,std::string name);
		std::string name;
	private:
		char randomness;
	};

	void LevelController::startLevel(LevelController::Initializer initializer);

	LevelController::Initializer LEVEL_ONE{ (char)100, "Resources/Levels/init.level" };

	//add GameObject
	//
	//This function will put a new GameObject under the control of the GameController.
	void LevelController::addObject(GameObject * object);

	//remove GameObject
	//
	//This function will remove a GameObject under the control of the GameController, and DESTROY the GameObject in question.
	void LevelController::removeObject(GameObject * object);

	void LevelController::step(float fps, sf::RenderWindow & window);

	~LevelController();

private:

	sf::Texture background;
	sf::Texture backgroundOverlay;

	sf::Sprite backgroundSprite;
	sf::Sprite backgroundSpriteOverlay;

	sf::Uint8 terrorLevel = 255;

	std::vector< GameObject* > gameObjects;
	
};