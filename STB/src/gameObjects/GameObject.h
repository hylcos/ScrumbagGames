#pragma once
#include <SFML/Graphics.hpp>
#include "..\LevelController.h"

class GameObject
{
public:
	GameObject(LevelController & levelCtrl);

	virtual void GameObject::update(float speedModifier);
	virtual void GameObject::move(float speedModifier);
	virtual void GameObject::draw(sf::RenderWindow & window) const;

	virtual ~GameObject();
private:
	LevelController & levelController;
};

