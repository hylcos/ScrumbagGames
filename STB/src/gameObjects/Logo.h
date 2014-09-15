#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

class Logo :
	public GameObject
{
public:
	Logo(LevelController & levelController) : GameObject(levelController){};

	void Logo::draw(sf::RenderWindow & window) const override;

	~Logo();
private:
	sf::Texture Logo::texture;
	sf::Sprite Logo::logo;
};

