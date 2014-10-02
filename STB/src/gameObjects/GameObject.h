#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	GameObject(sf::Vector2f);

	virtual void GameObject::update(float speedModifier);
	virtual void GameObject::move(float speedModifier);
	virtual void GameObject::draw(sf::RenderWindow & window) const;
	virtual void GameObject::next();
	void GameObject::setPosition(sf::Vector2f position);
	virtual sf::FloatRect GameObject::getBounds();
	sf::Vector2f GameObject::getPosition();
	virtual void GameObject::setRotation(float rotate);

	void GameObject::setRandomness(sf::Uint8 terrorLevel);

	virtual ~GameObject();
protected:
	sf::Vector2f position;
};

