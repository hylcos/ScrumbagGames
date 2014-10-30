#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
#include "../LevelController.h"
#include "ParticleEmitter.h"

enum Powerups{
	fullHealth
	, doubleDamage
	, sprint
	, ammoUp
	, BAB
	//, invincibility
	//, instaKill
	//	, doubleReloadSpeed
	//, slowMotion
	//, miniGun
	//, sniperVision
	//, frenzy
	//, clone
	//, flamethrower
	//, doubleSpawn
	//, fog
	//, jam
	//, blind
	, last
};
class Powerup : public GameObject, ParticleEmitter
{
public:
	class Types{
	public:
		Types(Powerups type, void(Powerup::*action)());
		void executeAction(Powerup & powerup);
		Powerups getType();
	private:
		Powerups type;
		void(Powerup::*action)();
	};
	Powerup::Powerup(sf::Vector2f position);

	Powerup* Powerup::setType(Powerup::Types* type);
	Powerup::Types puAmmoUp{ Powerups::ammoUp, &Powerup::pufAmmoUp };
	Powerup::Types puSprint{ Powerups::sprint, &Powerup::pufDoubleSpeed };
	Powerup::Types puFullHealth{ Powerups::fullHealth, &Powerup::pufFullHealth };
	Powerup::Types BAB{ Powerups::BAB, &Powerup::pufBAB };
	void Powerup::update(float speedModifier);

	sf::FloatRect Powerup::getBounds()  override;
	void Powerup::draw(sf::RenderWindow & window) const override;
	Powerups Powerup::getPowerup();
	void Powerup::pufAmmoUp();
	void Powerup::pufDoubleSpeed();
	void Powerup::pufFullHealth();
	void Powerup::pufBAB();

	~Powerup();
private:
	Types* type = nullptr;
	sf::Texture tex;
	sf::Sprite sprite;
	Powerups power;
};

