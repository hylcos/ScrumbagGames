//! The Bobby Boss header file
/*!
This is the header file of the Bobby Boss class.
*/
#pragma once
#include "../Enemy.h"

class bobbyBoss : public Enemy
{
public:
	//! The Bobby Boss Constructor
	/*!
	Loads the images for the animation of this boss. Also sets the animation for when the boss hits the player.
	*/
	bobbyBoss();

	//! The update method of the Bobby Boss
	/*!
	Mainly checks the timer to see if it is time to spawn the boss.
	When the timer ends, the boss will spawn at a random position on the map.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void bobbyBoss::update(float speedModifier) override;

	//! The draw method of the Bobby Boss
	/*!
	Draws the boss when it is spawned.
	@param window The window in which the boss has to be spawned.
	*/
	void bobbyBoss::draw(sf::RenderWindow &  window) const override;

	//! The move method of the Bobby Boss
	/*!
	Moves the boss in the direction of the player when it is spawned.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void bobbyBoss::move(float speedModifier) override;

	//! The reduceHP method of the Bobby Boss
	/*!
	Tells the Bobby Boss what it should do when the boss gets hit.
	@param damage The amount of damage dealt to the boss
	*/
	void bobbyBoss::reduceHP(int damage) override;

	//! The deconstructor of the Bobby Boss
	/*!
	The default constructor of the boss
	*/
	~bobbyBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
};

