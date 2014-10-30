//! The game object header file
/*!
This is the header file of the game object class.
*/
#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:

	//! the gameObject type enum for the game object class
	/*!
	In this enum it is specified what type of object this game object is.
	*/
	static enum gameObjectType{
		unspecified,
		enemy,
		player,
		table,
		bench,
		trashcan,
		powerup,
		weapon,
		particle,
		particleManager
	};

	//! The standard constructor of the gameobject
	/*!
	a default constructor that only sets the type of this game object.
	*/
	GameObject(gameObjectType type = unspecified);

	//! The constructor used if a position is given for the initialization of a game object.
	/*!
	the default constructor, but also sets the position of the game object with the initialization.
	*/
	GameObject(sf::Vector2f pos, gameObjectType type = unspecified);

	//! The update method of the game object
	/*!
	Virtual method that will specify what happens when the game object is updated
	@param speedModifier The speed of the game based on the framerate
	*/
	virtual void GameObject::update(float speedModifier);

	//! The move method of the game object
	/*!
	Virtual method that will specify what happens when the game object is told to move
	@param speedModifier The speed of the game based on the framerate
	*/
	virtual void GameObject::move(float speedModifier);

	//! The draw method of the game object
	/*!
	Virtual method that will specify what happens when the game object has to be drawn
	@param window The window the game object has to be drawn in
	*/
	virtual void GameObject::draw(sf::RenderWindow & window) const;

	//! The next method of the game object
	/*!
	Virtual method that will specify what happens when the game object is told to go to the next frame (probably used for animations).
	*/
	virtual void GameObject::next();

	//! The set position method of the game object
	/*!
	Virtual method that will set the position of the game object
	@param position The position that the game object's will be set to
	*/
	void GameObject::setPosition(sf::Vector2f position);

	//! The get bounds method of the game object
	/*!
	@return A rectangle indicating the bounds of the game object
	*/
	virtual sf::FloatRect GameObject::getBounds();

	//! the get position method of the game object
	/*!
	@return the position of the game object
	*/
	sf::Vector2f GameObject::getPosition();

	//! The get transform method of the game object
	/*!
	@return The real bounds of the game object, also indicating the rotation
	*/
	virtual sf::Transform GameObject::getTransform();

	//! The get size method of the game object
	/*!
	@return the size of the game object
	*/
	virtual sf::Vector2u GameObject::getSize();

	//! The set rotation method of the game object
	/*!
	@param rotate the rotation the game object's has to be set to.
	*/
	virtual void GameObject::setRotation(float rotate);

	//! The get type method of the game object
	/*!
	@return the type of game object this game object is
	*/
	gameObjectType GameObject::getType();

	//! The set randomness method of the game object
	/*!
	@param terrorLevel the terror level of the game object. This will set how much the position and rotation can deviate from the originally given settings.
	*/
	void GameObject::setRandomness(sf::Uint8 terrorLevel);

	//! The deconstructor of the game object
	/*!
	Will deallocate the game object.
	*/
	virtual ~GameObject();

protected:
	sf::Vector2f position;
	gameObjectType type;
};

