#include "../stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}

void GameObject::update(float speedModifier){

}

void GameObject::setPosition(sf::Vector2f position){
	GameObject::position.x = position.x;
	GameObject::position.y = position.y;
}

void GameObject::move(float speedModifier){

}

void GameObject::draw(sf::RenderWindow & window) const{
}

GameObject::~GameObject()
{
}
