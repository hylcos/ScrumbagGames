#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();

	virtual void GameObject::update(float speedModifier);
	virtual void GameObject::move(float speedModifier);
	virtual void GameObject::draw(sf::RenderWindow & window) const;
	void GameObject::setPosition(sf::Vector2f position);

	virtual ~GameObject();
protected:
	sf::Vector2f position;
};

