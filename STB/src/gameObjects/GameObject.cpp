#include "../stdafx.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>


GameObject::GameObject(gameObjectType type):
type{ type }
{

}

GameObject::GameObject(sf::Vector2f pos) :
position{pos}
{
}

void GameObject::setRandomness(sf::Uint8 terrorLevel){
	if (terrorLevel <= 0){
		return;
	}
	setRotation(((rand() % terrorLevel) - terrorLevel / 2.0f) / 255.0f * 360.0f);
	GameObject::position.x += (rand() % terrorLevel) / 255.0f * 128.0f - 64.0f;
	GameObject::position.y += (rand() % terrorLevel) / 255.0f * 128.0f - 64.0f;
}

void GameObject::update(float speedModifier){

}
void GameObject::next(){

}

void GameObject::setRotation(float rotate){

}

void GameObject::setPosition(sf::Vector2f position){
	GameObject::position = position;
}

sf::Vector2f GameObject::getPosition(){
	return position;
}

void GameObject::move(float speedModifier){

}

sf::FloatRect GameObject::getBounds(){
	return sf::RectangleShape{}.getGlobalBounds();
}

void GameObject::draw(sf::RenderWindow & window) const{
}

GameObject::gameObjectType GameObject::getType(){
	return type;
}
GameObject::~GameObject()
{
}
