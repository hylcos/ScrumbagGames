//! The Ethan Boss header file
/*!
This is the header file of the Ethan Boss class.
*/
#pragma once
#include "../Enemy.h"

class ethanBoss : public Enemy
{
public:
	//! The Ethan Boss Constructor
	/*!
	Loads the images for the animation of this boss. Also sets the animation for when the boss hits the player.
	*/
	ethanBoss();

	//! The update method of the Ethan Boss
	/*!
	Mainly checks the timer to see if it is time to spawn the boss.
	When the timer ends, the boss will spawn at a random position on the map.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void ethanBoss::update(float speedModifier) override;

	//! The draw method of the Ethan Boss
	/*!
	Draws the boss when it is spawned.
	@param window The window in which the boss has to be spawned.
	*/
	void ethanBoss::draw(sf::RenderWindow &  window) const override;

	//! The move method of the Ethan Boss
	/*!
	Moves the boss in the direction of the player when it is spawned.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void ethanBoss::move(float speedModifier) override;

	//! The reduceHP method of the Ethan Boss
	/*!
	Tells the Ethan Boss what it should do when the boss gets hit.
	@param damage The amount of damage dealt to the boss
	*/
	void ethanBoss::reduceHP(int damage) override;

	//! hp bar method
	void ethanBoss::showHp();
	//! The deconstructor of the Ethan Boss
	/*!
	The default constructor of the boss
	*/
	~ethanBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround, healthBackGround;
};

