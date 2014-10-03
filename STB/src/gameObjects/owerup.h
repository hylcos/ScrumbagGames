#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
enum Powerups{
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
class Powerup : public GameObject
{
public:
	class Types{
	public: 
		Types(Powerups type, void(*action)());
		void executeAction();
		Powerups getType();
	private:
		Powerups type;
		void (*action)();
	};
	Powerup::Types sprint{ Powerups::sprint, LevelController::getInstance().getPlayer()->doubleSpeed };
	Powerup::Types fullHealth{ Powerups::fullHealth, LevelController::getInstance().getPlayer()->fullHealth };
	Powerup(sf::Vector2f position, int power = 0);

	sf::FloatRect Powerup::getBounds()  override;
	void Powerup::draw(sf::RenderWindow & window) const override;
	Powerups Powerup::getPowerup();
	~Powerup();
private:
	sf::Texture tex;
	sf::Sprite sprite;
	Powerups power;
};

