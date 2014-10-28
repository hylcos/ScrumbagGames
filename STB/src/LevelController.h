#pragma once
#include "GameController.h"
#include "Factory.h"
#include "gameObjects\Player.h"
#include <SFML\Graphics.hpp>
#include <unordered_set>
#include "gameObjects\menu\Resume.h"
#define PI 3.14159265358979323846f
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

	void LevelController::goToNextLevel(LevelController::Initializer * initializer);
	void LevelController::startLevel(LevelController::Initializer initializer);

	LevelController::Initializer LEVEL_ONE{ "Resources/Levels/levelOne.level" };
	LevelController::Initializer MENU_MAIN{ "Resources/Levels/mainMenu.level" };
	LevelController::Initializer MENU_OPTIONS{ "Resources/Levels/optionsMenu.level" };

	//add GameObject
	//
	//This function will put a new GameObject under the control of the GameController.
	void LevelController::addObject(GameObject * object);

	void LevelController::addObjectFromFactory(GameObject * object);
	//remove GameObject
	//
	//This function will remove a GameObject under the control of the GameController, and DESTROY the GameObject in question.
	void LevelController::removeObject(GameObject * object);

	void LevelController::removeAllObjects(GameObject * object);
	//Move the main view
	void LevelController::moveMainView(sf::Vector2f pos);
	void LevelController::moveMainView(float x, float y);

	//Set the main view position
	void LevelController::setMainView(sf::Vector2f pos);
	void LevelController::setMainView(float x, float y);

	void LevelController::setPaused();
	void LevelController::step(float fps, sf::RenderWindow & window);

	Player * LevelController::getPlayer();

	sf::Vector2f LevelController::getMousePos();

	const std::vector< GameObject* > LevelController::getGameObjects();

private:
	LevelController() {};
	LevelController(LevelController const&) = delete;
	void operator=(GameController const&) = delete;

	void LevelController::load();
	bool isLoaded = false;
	bool paused = false;
	bool pausedPressed = false;

	void LevelController::stopLevel();

	sf::View mainView;

	Initializer* nextLevel = nullptr;

	sf::Vector2f viewMovement{ 0,0 };

	sf::Texture background;
	sf::Texture backgroundOverlay;
	sf::Texture pauseOverlay;

	sf::Sprite pauseSprite;
	sf::Sprite backgroundSprite;
	sf::Sprite backgroundSpriteOverlay;

	sf::Uint8 terrorLevel = 255;

	std::vector< GameObject* > gameObjects, gameObjectToAdd;
	std::unordered_set<GameObject*> gameObjectToRemove;
	
	MainMenu backToMenu;
	Play restart;
	Resume resume;
	Player * player = nullptr;
};