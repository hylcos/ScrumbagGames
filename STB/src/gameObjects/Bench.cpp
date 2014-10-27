#include "../stdafx.h"
#include "Bench.h"
#include "GameObject.h"
#include "../TextureManager.h"
Bench::Bench() :
GameObject{ gameObjectType::bench }
{
	pic = TextureManager::getInstance().getTexture("Sprites/Bench.png");
	bench.setOrigin(pic->getSize().x / 2.0f, pic->getSize().y / 2.0f);
	bench.setTexture(*pic);
}

void Bench::update(float speedmodifer){
	bench.setPosition(position);
}

void Bench::setRotation(float rotate){
	bench.rotate(rotate);
}

void Bench::draw(sf::RenderWindow & window) const{
	window.draw(bench);
}
sf::FloatRect Bench::getBounds() {
	return bench.getLocalBounds();
}

sf::Transform Bench::getTransform(){
	return bench.getTransform();

}sf::Vector2u Bench::getSize(){
	return pic->getSize();
}