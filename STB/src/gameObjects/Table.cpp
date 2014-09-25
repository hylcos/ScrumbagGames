#include "../stdafx.h"
#include "Table.h"
#include "../TextureManager.h"
#include "GameObject.h"

Table::Table()
{
	tex = TextureManager::getTexture("table.png");
}

void Table::draw(sf::RenderWindow & window) const{

	//tab = TextureManager::getTexture("table.png");
	//loadFromFile("texture.png");
	//sf::Sprite sprite;
	//sprite.setTexture(*tab);
	//window.draw(sprite);
}


Table::~Table(){}

