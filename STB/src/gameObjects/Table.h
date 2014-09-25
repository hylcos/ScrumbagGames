#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
#include <SFML\Graphics.hpp>
class Table :
	public GameObject
{
public:
	Table();
	//static Table table();
	void Table::draw(sf::RenderWindow & window) const override;
	~Table();

private:
	sf::Uint8 state;
	sf::Texture * tex;
	sf::Sprite table;
	};
