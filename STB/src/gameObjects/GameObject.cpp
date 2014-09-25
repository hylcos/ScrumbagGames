#include "../stdafx.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>


GameObject::GameObject()
{
}

GameObject::GameObject(sf::Vector2f pos) :
position{pos}
{
}

void GameObject::update(float speedModifier){

}

void GameObject::setPosition(sf::Vector2f position){
	GameObject::position.x = position.x;
	GameObject::position.y = position.y;
}

sf::Vector2f GameObject::getPosition(){
	return position;
}

void GameObject::move(float speedModifier){

}

void GameObject::draw(sf::RenderWindow & window) const{
}

GameObject::~GameObject()
{
}
