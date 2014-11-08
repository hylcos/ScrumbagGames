#include "../stdafx.h"
#include "Table.h"
#include "../TextureManager.h"
#include "GameObject.h"

Table::Table():
GameObject{gameObjectType::table}
{
	tex = TextureManager::getInstance().getTexture("Sprites/Table.png");
	table.setOrigin(tex->getSize().x / 2.0f, tex->getSize().y / 2.0f);
	table.setTexture(*tex);
}

void Table::update(float speedmodifer){
	table.setPosition(position);
}

void Table::setRotation(float rotate){
	table.rotate(rotate);
}


void Table::draw(sf::RenderWindow & window) const{

	window.draw(table);
}

sf::FloatRect Table::getBounds() {
	return table.getLocalBounds();
}

sf::Transform Table::getTransform(){
	return table.getTransform();

}
Table::~Table(){}

