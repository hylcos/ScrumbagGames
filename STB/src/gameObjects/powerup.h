#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
enum powerups{
	fullHealth
	,doubleDamage
	,doubleReloadSpeed
	,BAB
	,invincibility
	,instaKill
	,sprint
	,slowMotion
	,miniGun
	,sniperVision
	,frenzy
	,clone
	,flamethrower
	,doubleSpawn
	,fog
	,jam
	,blind
	,last
};
class powerup : public GameObject
{
public:
	powerup(sf::Vector2f position);
	~powerup();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	powerups p;
};

