//! The game object manager header file
/*!
This is the header file of the game object manager class.
*/
#pragma once
#include "GameObject.h"
#include "ParticleManager.h"
#include "Circle.h"
#include "Logo.h"
#include "Player.h"
#include <string>
#include "Table.h"
#include "Bench.h"
#include "Enemy.h"
#include "menu\play.h"
#include "menu\Options.h"
#include "menu\MainMenu.h"
#include "menu\Checkbox.h"
#include "menu\ToggleMusic.h"
#include "menu\ToggleSound.h"
#include "menu\ToggleGore.h"
#include "menu\MusicSlider.h"
#include "menu\SoundSlider.h"

class GameObjectManager
{
public:

	//! The constructor of the game object manager
	/*!
	the default constructor.
	*/
	GameObjectManager();

	//! The create object from name method of the game object manager
	/*!
	initializes a game object based on the name given to this method.
	@param string The name of the game object that has to be created.
	@return A pointer to the initialized game object.
	*/
	GameObject * GameObjectManager::createObjectFromName(std::string string);

	//! The deconstructor of the game object manager
	/*!
	Deallocates the game object manager
	*/
	~GameObjectManager();
};

