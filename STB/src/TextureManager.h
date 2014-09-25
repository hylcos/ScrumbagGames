#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

class TextureManager
{
public:
	TextureManager();
	static sf::Texture getTexture(std::string name);
	static 
	~TextureManager();
};

