#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager();
	static sf::Texture getTexture(std::string name);
	~TextureManager();
};

