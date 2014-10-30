#include "../stdafx.h"
#include "Trashcan.h"
#include "GameObject.h"
#include "../TextureManager.h"

Trashcan::Trashcan() :
GameObject{ gameObjectType::trashcan }
{
	pic = TextureManager::getInstance().getTexture("Sprites/Trashcan.png");
	trashcan.setOrigin(pic->getSize().x / 2.0f, pic->getSize().y / 2.0f);
	trashcan.setTexture(*pic);
}

void Trashcan::update(float speedmodifer){
	trashcan.setPosition(position);
}

void Trashcan::setRotation(float rotate){
	trashcan.rotate(rotate);
}

void Trashcan::draw(sf::RenderWindow & window) const{
	window.draw(trashcan);
}
sf::FloatRect Trashcan::getBounds() {
	return trashcan.getLocalBounds();
}

sf::Transform Trashcan::getTransform(){
	return trashcan.getTransform();

}sf::Vector2u Trashcan::getSize(){
	return pic->getSize();
}