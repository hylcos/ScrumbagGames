#include "stdafx.h"
#include "TextureManager.h"
#include <map>

sf::Texture* TextureManager::getTexture(std::string name){
	std::map<std::string, sf::Texture*>::iterator it = map.find(name);
	if (it != map.end())
	{
		//element found;
		return it->second;
	}
	sf::Texture* tex = new sf::Texture();
	tex->setSmooth(true);
	tex->loadFromFile("Resources/Images/" + name);
	map.insert(std::pair<std::string, sf::Texture*>(name, tex));
	return tex;
}