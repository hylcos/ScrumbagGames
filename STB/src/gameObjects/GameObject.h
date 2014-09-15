#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();

	virtual void GameObject::update(float speedModifier);
	virtual void GameObject::move(float speedModifier);
	virtual void GameObject::draw(sf::RenderWindow & window) const;

	virtual ~GameObject();
};

