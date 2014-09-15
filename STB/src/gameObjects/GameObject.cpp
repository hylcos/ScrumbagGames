#include "../stdafx.h"
#include "GameObject.h"
#include "..\LevelController.h"


GameObject::GameObject(LevelController & levelController):
levelController{levelController}
{
}

void GameObject::update(float speedModifier){

}

void GameObject::move(float speedModifier){

}

void GameObject::draw(sf::RenderWindow & window) const{
}

GameObject::~GameObject()
{
}
