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
	//! The getTexture method
	/*!
	This method will return or make a texture.
	@param name of the Texture the user wants to get
	@return the Texture the user want
	*/
	sf::Texture* TextureManager::getTexture(std::string name);
private:

	std::map < std::string, sf::Texture* > map;
	TextureManager() {};
	TextureManager(TextureManager const&);
	void operator=(TextureManager const&);
};

