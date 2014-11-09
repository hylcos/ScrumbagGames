#pragma once
#include "../../Clickable.h"
#include "../../Weapon.h"
class Upgrade : public Clickable
{
public:
	//! This enum represents the 3 possible upgrades the player can apply to any weapon.
	enum types{
		FireRate,
		Damage,
		ReloadSpeed
	};

	//! The constructor of the upgrade class
	/*!
	The constructor will load in the image of the upgrade button and will set a text according to which upgrade that button represents.
	@param weapon The weapon that can be upgraded
	@param type The type of this particular weapon
	*/
	Upgrade(Weapon * weapon,types type);

	//! the update method of the upgrade class
	/*!
	This method will fill the upgrade bar with however far the weapon is upgraded.
	It will also manage the stats of the weapon that has to be upgraded.
	@param speedModifier A value in our game that represents the speed of the frames the game is currently running at.
	*/
	void Upgrade::update(float speedModifier) override;

	//! The draw method of the upgrade class
	/*!
	This method will draw the button, text, and draw the amount of upgrades applied to the weapon
	@param window The window in which everything has to be drawn.
	*/
	void Upgrade::draw(sf::RenderWindow & window) const override;

	//! the click method of the upgrade class
	/*!
	This method manages what happens when the player clicks on a button to upgrade.
	*/
	void Upgrade::click() override;

	//! The get bounds method of the upgrade class
	/*!
	@return The bounds of the upgrade button
	*/
	sf::FloatRect Upgrade::getBounds() override;

	//! The update weapon method of the upgrade weapon class
	/*!
	This method will update the statistics of the weapon it represents when the player chooses to upgrade it.
	*/
	void Upgrade::updateWeapon(Weapon * weapon);

	//! The deconstructor of the upgrade class
	/*!
	The default deconstructor
	*/
	~Upgrade();
private:
	sf::RectangleShape backGround[5];
	sf::RectangleShape foreGround[5];
	sf::Text text;
	types type;
	sf::Sprite sprite;
	sf::Texture tex;
	int UpgradeLevel;
	Weapon * weapon;
};

