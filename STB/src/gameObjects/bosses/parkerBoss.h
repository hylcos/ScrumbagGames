//! The Parker Boss header file
/*!
This is the header file of the Parker Boss class.
*/
#pragma once
#include "../Enemy.h"

class parkerBoss : public Enemy
{
public:
	//! The Parker Boss Constructor
	/*!
	Loads the images for the animation of this boss. Also sets the animation for when the boss hits the player.
	*/
	parkerBoss();

	//! The update method of the Parker Boss
	/*!
	Mainly checks the timer to see if it is time to spawn the boss.
	When the timer ends, the boss will spawn at a random position on the map.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void parkerBoss::update(float speedModifier) override;

	//! The draw method of the Parker Boss
	/*!
	Draws the boss when it is spawned.
	@param window The window in which the boss has to be spawned.
	*/
	void parkerBoss::draw(sf::RenderWindow &  window) const override;

	//! The move method of the Parker Boss
	/*!
	Moves the boss in the direction of the player when it is spawned.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void parkerBoss::move(float speedModifier) override;

	//! The reduceHP method of the Parker Boss
	/*!
	Tells the Parker Boss what it should do when the boss gets hit.
	@param damage The amount of damage dealt to the boss
	*/
	void parkerBoss::reduceHP(int damage) override;

	//! hp bar method
	/*!
	Shows the hp bar of the Parker Boss, and changes it according to how much hp the Parker Boss has left.
	*/
	void parkerBoss::showHp();
	//! The deconstructor of the Parker Boss
	/*!
	The default constructor of the boss
	*/
	~parkerBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround, healthBackGround;
};

