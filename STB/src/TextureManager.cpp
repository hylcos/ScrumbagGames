#include "stdafx.h"
#include "TextureManager.h"
#include <map>


TextureManager::TextureManager()
{
}

static sf::Texture* getTexture(std::string name){
	std::map<std::string, sf::Texture*>::iterator it =TextureManager::map.find(name);
	if (it != TextureManager::map.end())
	{
		//element found;
		return it->second;
	}
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile("Resources/Images/" + name);
	TextureManager::map.insert(std::pair<std::string,sf::Texture*>(name, tex));
	return tex;
}

TextureManager::~TextureManager()
{
}
