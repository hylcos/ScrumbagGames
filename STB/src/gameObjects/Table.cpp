#include "../stdafx.h"
#include "Table.h"
#include "../TextureManager.h"
#include "GameObject.h"

Table::Table()
{
	tex = TextureManager::getInstance().getTexture("/sprites/table.png");
	table.setTexture(*tex);
}

void Table::draw(sf::RenderWindow & window) const{

	window.draw(table);
}


Table::~Table(){}

