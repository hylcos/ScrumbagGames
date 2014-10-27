#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	static enum gameObjectType{
		unspecified,
		enemy,
		player,
		table,
		bench,
		powerup,
		weapon
	};
	GameObject(gameObjectType type = unspecified);
	GameObject(sf::Vector2f);

	virtual void GameObject::update(float speedModifier);
	virtual void GameObject::move(float speedModifier);
	virtual void GameObject::draw(sf::RenderWindow & window) const;
	virtual void GameObject::next();
	void GameObject::setPosition(sf::Vector2f position);
	virtual sf::FloatRect GameObject::getBounds();
	sf::Vector2f GameObject::getPosition();
	virtual sf::Transform GameObject::getTransform();
	virtual sf::Vector2u GameObject::getSize();
	virtual void GameObject::setRotation(float rotate);
	gameObjectType GameObject::getType();

	void GameObject::setRandomness(sf::Uint8 terrorLevel);

	virtual ~GameObject();
protected:
	sf::Vector2f position;
	gameObjectType type;
};

