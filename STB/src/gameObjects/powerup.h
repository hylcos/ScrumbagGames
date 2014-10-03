#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
enum powerups{
	fullHealth
	, doubleDamage
	, doubleReloadSpeed
	, BAB
	, invincibility
	, instaKill
	, sprint
	, slowMotion
	, miniGun
	, sniperVision
	, frenzy
	, clone
	, flamethrower
	, doubleSpawn
	, fog
	, jam
	, blind
	, last
};
class powerup : public GameObject
{
public:
	class Types{
	public: 
		Types(powerups type, void(*action)());
		void executeAction();
		powerups getType();
	private:
		powerups type;
		void (*action)();
	};
	powerup::Types sprint{ powerups::sprint, LevelController::getInstance().getPlayer()->doubleSpeed };
	powerup::Types fullHealth{ powerups::fullHealth, LevelController::getInstance().getPlayer()->fullHealth };
	powerup(sf::Vector2f position, int power = 0);

	sf::FloatRect powerup::getBounds()  override;
	void powerup::draw(sf::RenderWindow & window) const override;
	powerups powerup::getPowerup();
	~powerup();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	powerups power;
};

