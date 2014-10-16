#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_set>
#include "gameObjects\GameObject.h"

class HudController
{
public:
	static HudController& getInstance()
	{
		static HudController    instance;
		instance.load();
		return instance;
	}
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

