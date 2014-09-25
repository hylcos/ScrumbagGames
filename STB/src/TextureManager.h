#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

class TextureManager
{
public:
	static TextureManager& getInstance()
	{
		static TextureManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}
	sf::Texture* TextureManager::getTexture(std::string name);
	std::map < std::string, sf::Texture* > TextureManager::map;
private:
	TextureManager() {};
	TextureManager(TextureManager const&);
	void operator=(TextureManager const&);
};

