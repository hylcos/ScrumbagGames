#pragma once
#include "GameObject.h"
#include "../TextureManager.h"
#include "../LevelController.h"
#include "ParticleEmitter.h"

	enum Powerups{
		fullHealth = 0
		, doubleDamage
		, sprint
		, ammoUp
		, BAB
		, Money
		//, invincibility
		//, instaKill
		//, doubleReloadSpeed
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
	static const char* PowerupNames[last] = {
		"Full Health"
		, "Double Damage"
		, "Sprint"
		, "Ammo Up"
		, "Big Ass Bomb"
		, ""//money
	};


class Powerup : public GameObject, ParticleEmitter
{
public:
	
	//! The Types class 
	/*!
	this is made to pre-make different Powerups
	*/
	class Types{
		
	public:
		//! Constructor method for types
		/*!
		Makes a new Powerup
		@param type which type the power up is
		@param action which method must be called when powerup is activated
		*/
		Types(Powerups type, void(Powerup::*action)());

		//! the executeAction method
		/*!
		calls the method that belings to the powerup
		@param pwerup which action must be executed
		*/
		void executeAction(Powerup & powerup);
	private:
		Powerups type;
		void(Powerup::*action)();
	};

	//! Constructor method for Powerups
	/*!
	The constructor of Powerups gets the needed texture from the texture manager.
	It also sets the origin of the sprite to the middle of the texture.
	Configures the PowerupText that comes in the screen when you will pick up a powerup
	@param position The position on which the powerup must be spawned
	*/
	Powerup::Powerup(sf::Vector2f position);

	//! The SetType  method for Powerups
	/*!
	sets the type of this powerup. So what it must do when the player intersects with the powerup
	@param type which type the power up is
	*/
	Powerup* Powerup::setType(Powerup::Types* type);

	//! The PowerUp Type Ammo up
	Powerup::Types puAmmoUp{ Powerups::ammoUp, &Powerup::pufAmmoUp };

	//! The PowerUp Type Sprint
	Powerup::Types puSprint{ Powerups::sprint, &Powerup::pufDoubleSpeed };

	//! The PowerUp Type Double Damage
	Powerup::Types puDoubleDamage{ Powerups::doubleDamage, &Powerup::pufDoubleDamage };

	//! The PowerUp Type Full Health
	Powerup::Types puFullHealth{ Powerups::fullHealth, &Powerup::pufFullHealth };

	//! The PowerUp Type Big Ass Bomb
	Powerup::Types BAB{ Powerups::BAB, &Powerup::pufBAB };

	//! The PowerUp Type Money
	Powerup::Types Money{ Powerups::Money, &Powerup::addMoney };

	//! Updates the sprite of the Trashcan
	/*!
	Updates the position of the Trashcan and changes the position of the text so it above the head of the player
	Also Checks if powerup and the player collide. If True the action that belongs to the powerup is executed
	and there is a timer set for the text. which is set to 300 ( 5 Second) and the isLoaded is set True
	In The following 5 seconds the Text will slowely dissapear and the will delete itself 
	from the LevelController GameObject list
	@param speedModifier isn't really used but is here because of the override.
	*/
	void Powerup::update(float speedModifier);

	//! The Draw method of the Powerup
	/*!
	Draws the current sprite of the Powerup on the screen if it isn't been picked up. 
	If It's then it will draw the Powerup Text on the screen
	@param window the screen on which the Powerup or Powerup text should be drawn.
	*/
	void Powerup::draw(sf::RenderWindow & window) const override;

	//! The pufAmmoUp method of the Powerup
	/*!
	Calls the method AmmoUp in the current selected weapon which gives the weapon 
	two extra magazines
	*/
	void Powerup::pufAmmoUp();

	//! The pufDoubleDamage method of the Powerup
	/*!
	Calls the method doubleDamage in the current selected weapon which 
	gives the weapon a damage boost for a small amount of time
	*/
	void Powerup::pufDoubleDamage();

	//! The pufDoubleSpeed method of the Powerup
	/*!
	Calls the method Double Speed in Player so the player gets a speed boost
	for a smaal amount of time
	*/
	void Powerup::pufDoubleSpeed();

	//! The pufFullHealth method of the Powerup
	/*!
	Calls the method full health in Player which gives the player full health
	*/
	void Powerup::pufFullHealth();

	//! The pufBAB method of the Powerup
	/*!
	Spawns a lot of Particals in all the different directions
	and deals 1000 damage to every enemy on the screen
	*/
	void Powerup::pufBAB();

	//! The addMoney method of the Powerup
	/*!
	Generates a number between 25 and 50 and adds that number to the money of the player
	*/
	void Powerup::addMoney();

	//! The setNumber method of the Powerup
	/*!
	sets which number of all the powerups in the powerup enum this powerup is
	*/
	void Powerup::setNumber(int & number);

	//! The deconstructor  of a Powerup
	/*!

	*/
	~Powerup();

private:
	int powerupnumber;
	bool isLoaded;
	int moneyAmount;
	float showtextTimer;
	sf::Font font;
	sf::Text poweruptext;
	Types* type = nullptr;
	sf::Texture tex;
	sf::Sprite sprite;
	Powerups power;
};

