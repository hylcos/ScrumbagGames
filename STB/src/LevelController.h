//! The level controller header file
/*!
This is the header file of the level controller
*/
#pragma once
#include "GameController.h"
#include "TextureManager.h"
#include "gameObjects\ParticleManager.h"
#include "Factory.h"
#include "gameObjects\Player.h"
#include <SFML\Graphics.hpp>
#include <unordered_set>
#include "gameObjects\menu\Resume.h"
#include "gameObjects\menu\Shop.h"
#define PI 3.14159265358979323846f
class GameController;
class LevelController
{
public:

	//! The get instance method of the level controller
	/*!
	This method ensures that every class that asks for a reference gets the same one.
	@return The reference to the level controller
	*/
	static LevelController& getInstance()
	{
		static LevelController    instance;
		instance.load();
		return instance;
	}

	//! The initializer is used to initialize some variables in advance.
	class Initializer{
	public:
		Initializer(std::string name);
		Initializer();
		std::string name;
	};

	//! The go to next level method of the level controller
	/*!
	This method will let the game progress to the next level
	@param initializer Has the data of the next level
	*/
	void LevelController::goToNextLevel(LevelController::Initializer * initializer);

	//! The start level method of the level controller
	/*!
	This method will start the level
	@param initializer Has data of the level that has to start.
	*/
	void LevelController::startLevel(LevelController::Initializer initializer);

	//! The location of the level one file
	LevelController::Initializer LEVEL_ONE{ "Resources/Levels/levelOne.level" };

	//! The location of the level two file
	LevelController::Initializer LEVEL_TWO{ "Resources/Levels/levelTwo.level" };

	//! The location of the level three file
	LevelController::Initializer LEVEL_THREE{ "Resources/Levels/levelThree.level" };

	//! The location of the level four file
	LevelController::Initializer LEVEL_FOUR{ "Resources/Levels/levelFour.level" };

	//! The location of the level five file
	LevelController::Initializer LEVEL_FIVE{ "Resources/Levels/levelFive.level" };

	//! The location of the file containing the main menu
	LevelController::Initializer MENU_MAIN{ "Resources/Levels/mainMenu.level" };

	//! The location of the file containing the options menu
	LevelController::Initializer MENU_OPTIONS{ "Resources/Levels/optionsMenu.level" };

	//! The location of the file containing the shop level
	LevelController::Initializer SHOP{ "Resources/Levels/shop.level" };

	//! The location of the file containing the tutorial level
	LevelController::Initializer TUTORIAL{ "Resources/Levels/tutorial.level" };

	//! The location of the file containing the splash art.
	LevelController::Initializer SPLASH{ "Resources/Levels/logo.level" };

	//! The set zoom method of the level controller
	/*!
	This method will allow us to zet the zoom level withing the game.
	@param f The amount the game should zoom in our out.
	*/
	void LevelController::setZoom(float f);
	
	//! The add Object method of the level controller
	/*!
	This method will add a pre excisting object to the game
	@param object The pointer to the object that has to be add
	*/
	void LevelController::addObject(GameObject * object);

	//! The add object from factory method of the level controller
	/*!
	When an object is created by the factory it can be directly put into the vector of game objects. Thats why there is a seperate method for this.
	@param object The object that has to be add to the game.
	*/
	void LevelController::addObjectFromFactory(GameObject * object);

	//! The remove object method of the level controller
	/*!
	This method will tell the level controller there is an object that can be removed from the game.
	@param object The object that has to be removed
	*/
	void LevelController::removeObject(GameObject * object);

	//! The remove all objects method of the level controller
	/*!
	Removes the given object from the list of game objects
	@param object the object that should be removed
	*/
	void LevelController::removeAllObjects(GameObject * object);
	
	//! The move main view method of the level controller
	/*!
	This method will move the view of the game to the specified position
	@param pos The position that has been specified
	*/
	void LevelController::moveMainView(sf::Vector2f pos);

	//! the move main view method using two coordinates
	/*!
	This method will move the view to a specified position using two coordinates
	@param x The x position the view has to move to
	@param y The y position the view has to move to
	*/
	void LevelController::moveMainView(float x, float y);

	//! The setMain view method of the level controller
	/*!
	Instead of moving to a certain position, this method will instantly set the view to a position
	@param pos The position the view should be set to
	*/
	void LevelController::setMainView(sf::Vector2f pos);

	//! The set main view method
	/*!
	This method will instantly set the view to the position given with two coordinates
	@param x The x position of the desired view location
	@param y THe y position of the desirec view location
	*/
	void LevelController::setMainView(float x, float y);

	//! The set paused method of the level controller
	/*!
	This method enables the game to be paused
	*/
	void LevelController::setPaused();

	//! The step method of the level controller
	/*!
	This method will update all the game objects, and then draw all of them.
	@param fps The amount of frames the game is currently generating each second
	@param window The window in which the game is running
	*/
	void LevelController::step(float fps, sf::RenderWindow & window);

	//! The reset method of the level controller
	/*!
	This metod will reset the entire game, setting all the attributes back to how they were at the launch of the game.
	*/
	void LevelController::reset();

	//! The get player method of the level controller
	/*!
	@return the pointer to the player object in the game
	*/
	Player * LevelController::getPlayer();
	
	//! The second get player method
	/*!
	@return the location of the copy of the player. Because the player gets removed at the end of a level, but still has to be used in the shop for example.
	*/
	Player * LevelController::getPlayer2();

	//! The get particle manager method of the level controller
	/*!
	@return the particle manager of the game
	*/
	ParticleManager * LevelController::getParticleManager();

	//! The get mouse position method of the level controller
	/*!
	@return the position of the players mouse cursor
	*/
	sf::Vector2f LevelController::getMousePos();

	//! The get game objects method of the level controller
	/*!
	@return the vector containing all of the game objects currently in the game.
	*/
	const std::vector< GameObject* > LevelController::getGameObjects();

	//! The go to next round method
	/*!
	Calling this method will cause the game to go to the next level.
	*/
	void LevelController::goToNextRound();

	//! an integer indicating the current level of the game.
	int curLevel = 0;
private:
	LevelController() {};
	LevelController(LevelController const&) = delete;
	void operator=(GameController const&) = delete;

	void LevelController::spawnEnemies(float speedModifier);
	void LevelController::load();
	bool isLoaded = false;
	bool paused = false;
	bool pausedPressed = false;

	void LevelController::stopLevel();

	sf::View mainView;

	Initializer* nextLevel = nullptr;

	sf::Vector2f viewMovement{ 0, 0 };

	sf::Texture background;
	sf::Texture backgroundOverlay;
	sf::Texture pauseOverlay;
	sf::Texture gameOverTexture;

	sf::Sprite gameOverSprite;
	sf::Sprite pauseSprite;
	sf::Sprite backgroundSprite;
	sf::Sprite backgroundSpriteOverlay;

	sf::Uint8 terrorLevel = 255;

	float targetZoom = 1.f;
	float curZoom = 1.f;

	std::vector< GameObject* > gameObjects, gameObjectToAdd;
	std::unordered_set<GameObject*> gameObjectToRemove;
	float enemySpawnTime;
	float timeToNextEnemySpawn=0;
	float gameOverTimer = 0.f;
	sf::Vector2f enemyPosition{0, 0};
	MainMenu backToMenu;
	Shop goToShop;
	Play restart;
	Resume resume;
	Player * player = nullptr;
	Player player2 ;
	ParticleManager * particleManager = nullptr;
};