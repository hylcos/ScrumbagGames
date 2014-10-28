//! The HUDController header file
/*!
This is the header file of the HUD controller class.
*/
#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_set>
#include "gameObjects\GameObject.h"

class HudController
{
public:

	//!The getInsatnce method of the HUD controller
	/*!
	This method makes sure there is only 1 instance of the HUD controller at a time.
	This way, every time an external class uses a HUD controller, it uses a HUD controller
	with the same attributes as every other class.
	@return
	*/
	static HudController& getInstance()
	{
		static HudController    instance;
		instance.load();
		return instance;
	}

	//! The add object method of the HUD controller
	/*
	
	*/
	//add GameObject
	//
	//This function will put a new GameObject under the control of the GameController.
	void HudController::addObject(GameObject * object);

	void HudController::addObjectFromFactory(GameObject * object);
	//remove GameObject
	//
	//This function will remove a GameObject under the control of the GameController, and DESTROY the GameObject in question.
	void HudController::removeObject(GameObject * object);

	void HudController::removeAllObjects(GameObject * object);

	void HudController::load();

	void HudController::step(sf::RenderWindow & window);

	sf::Vector2f HudController::getMousePos();
	
	void HudController::prepareForNextLevel();
	//const std::vector<GameObject *> HudController::getGameObjects();
	~HudController(){};
private:
	HudController() {};
	HudController(HudController const&);
	void operator=(HudController const&);

	bool isLoaded = false;

	sf::RectangleShape HPBackGround, HPForeGround;
	sf::RectangleShape ammoBackGround, ammoForeGround;
	sf::RectangleShape background;

	std::vector< GameObject* > gameObjects, gameObjectToAdd;
	std::unordered_set<GameObject*> gameObjectToRemove;
};

