//! The Zoey Boss header file
/*!
This is the header file of the Zoey Boss class.
*/
#pragma once
#include "../Enemy.h"

class zoeyBoss : public Enemy
{
public:
	//! The Zoey Boss Constructor
	/*!
	Loads the images for the animation of this boss. Also sets the animation for when the boss hits the player.
	*/
	zoeyBoss();

	//! The update method of the Zoey Boss
	/*!
	Mainly checks the timer to see if it is time to spawn the boss.
	When the timer ends, the boss will spawn at a random position on the map.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void zoeyBoss::update(float speedModifier) override;

	//! The draw method of the Zoey Boss
	/*!
	Draws the boss when it is spawned.
	@param window The window in which the boss has to be spawned.
	*/
	void zoeyBoss::draw(sf::RenderWindow &  window) const override;

	//! The move method of the Zoey Boss
	/*!
	Moves the boss in the direction of the player when it is spawned.
	@param speedModifier a modifier for anything using time, based on the amount of frames of the game.
	*/
	void zoeyBoss::move(float speedModifier) override;

	//! The reduceHP method of the Zoey Boss
	/*!
	Tells the Zoey Boss what it should do when the boss gets hit.
	@param damage The amount of damage dealt to the boss
	*/
	void zoeyBoss::reduceHP(int damage) override;

	//! hp bar method
	/*!
	Shows the hp bar of the Zoey Boss, and changes it according to how much hp the Zoey Boss has left.
	*/
	void zoeyBoss::showHp();
	//! The deconstructor of the Zoey Boss
	/*!
	The default constructor of the boss
	*/
	~zoeyBoss();
private:
	float timeToSpawn;
	sf::Texture tex;
	bool spawned = false;
	sf::RectangleShape healthForeGround, healthBackGround;
};

