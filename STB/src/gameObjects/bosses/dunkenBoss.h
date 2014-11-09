//! The Dunken Boss header file
/*!
This is the header file of the Dunken Boss class.
*/
#pragma once
#include "../Enemy.h"

class dunkenBoss : public Enemy
{
public:
	//! The Dunken Boss Constructor
	/*!
	Loads the images for the animation of this boss. Also sets the animation for when the boss hits the player.
	*/
	dunkenBoss();

	//! The update method of the Dunken Boss
	/*!
	Mainly checks the timer to see if it is time to spawn the boss.
	When the timer ends, the boss will spawn at a random position on the map.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void dunkenBoss::update(float speedModifier) override;

	//! The draw method of the Dunken Boss
	/*!
	Draws the boss when it is spawned.
	@param window The window in which the boss has to be spawned.
	*/
	void dunkenBoss::draw(sf::RenderWindow &  window) const override;

	//! The move method of the Dunken Boss
	/*!
	Moves the boss in the direction of the player when it is spawned.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void dunkenBoss::move(float speedModifier) override;

	//! The reduceHP method of the Dunken Boss
	/*!
	Tells the Dunken Boss what it should do when the boss gets hit.
	@param damage The amount of damage dealt to the boss
	*/
	void dunkenBoss::reduceHP(int damage) override;

	//! hp bar method
	void dunkenBoss::showHp();
	//! The deconstructor of the Dunken Boss
	/*!
	The default constructor of the boss
	*/
	~dunkenBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround, healthBackGround;
};

