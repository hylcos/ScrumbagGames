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
	@return The instance of the HUD controller
	*/
	static HudController& getInstance()
	{
		static HudController    instance;
		instance.load();
		return instance;
	}

	//! The add object method of the HUD controller
	/*!
	This function will put a new game object under the control of the game controller
	@param object The object that has to be added
	*/
	void HudController::addObject(GameObject * object);

	//! The add object from factory method of the hud controller
	/*!
	Puts an object created by the factory under control of the game controller
	@param object The object from the factory
	*/
	void HudController::addObjectFromFactory(GameObject * object);

	//! The remove object method of the hud controller
	/*!
	This function will remove a game object under the control of the game controller, and will destroy this particular game object.
	@param object The object that has to be removed
	*/
	void HudController::removeObject(GameObject * object);

	//! The remove all objects method of the hud controller
	/*!
	This method will remove the complete list of game objects
	@param object The pointer to the start of the object vector
	*/
	void HudController::removeAllObjects(GameObject * object);
	
	//! The load method of the hud controller
	/*!
	This method will set all the standard values for the HUD objects.
	*/
	void HudController::load();

	//! The step method of the HUD controller
	/*!
	This method will update every object from the HUD and draw them
	@param window The window on which the objects have to be drawn
	*/
	void HudController::step(sf::RenderWindow & window);

	//! the get mouse position method of the hud controller
	/*!
	@return The position of the mouse cursor.
	*/
	sf::Vector2f HudController::getMousePos();
	
	//! the prepare for next level method of the hud controller
	/*!
	deletes all the objects from the HUD to make place for the new objects of the next level
	*/
	void HudController::prepareForNextLevel();

	//! the deconstructor of the hud controller
	/*!
	default
	*/
	~HudController(){};

	//! this controlls the timer on screen en calculate how many minutes and seconds have passed
	/*!
	@param The time that is passed
	*/
	void HudController::updateTimer(float time);

	//! The method to set a string value on the timer
	/*!
	@param the string you want to set on the text
	*/
	void HudController::updateTimer(std::string value);

	//! The load method for al the HUD sprites
	/*!
	This method will load every texture for the HUD
	*/
	void HudController::loadHudTextures();

	//! The get method for the HUD view
	/*!
	@return  get the Hud view
	*/
	sf::View HudController::getHudView();

private:
	HudController() {};
	HudController(HudController const&);
	void operator=(HudController const&);

	sf::View hudView;
	sf::Font font;
	sf::Text ammotext, timetext, moneytext;
	sf::Sprite healthsprite, ammosprite, timesprite, buffssprite, riflesprite, pistolsprite, knifesprite, swordsprite, snipersprite, shotgunsprite;
	sf::Texture healthtex, ammotex, timetex, buffstex, rifletex, pistoltex, knifetex, swordtex, snipertex, shotguntex;
	bool isLoaded = false;
	void HudController::draw(sf::RenderWindow & window) const;
	sf::RectangleShape healthForeGround, ammoForeGround;

	std::vector< GameObject* > gameObjects, gameObjectToAdd;
	std::unordered_set<GameObject*> gameObjectToRemove;
};

