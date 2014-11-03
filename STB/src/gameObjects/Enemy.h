//! The Enemy header file
/*!
This is the header file of the enemy class.
*/
#pragma once
#include "Animation.h"
#include "../TextureManager.h"
#include <SFML\Graphics.hpp>
#include "ParticleEmitter.h"

class Enemy :
	public Animation, ParticleEmitter
{
private:
	class Initializer{
	public:
		Initializer(std::string name, float movementSpeed, int hp, bool melee, int damage, float attackSpeed);
		std::string getName();
		float getMovementSpeed();
		int getHP();
		bool isMelee();
		int getDamage();
		float getAttackSpeed();
	private:
		std::string name;
		float movementSpeed;
		int hp;
		bool melee;
		int damage;
		float attackSpeed;
	};
public:
	//! The constructor for the enemy class
	/*!
	Almost the default constructor. It also calls the animation constructor,
	to initialize an enemy as an animation.
	*/
	Enemy();

	//! The constructor for the enemy based of of an initializer
	/*!
	Initialize an enemy based on all the values of the given initializer.
	@param initializer An object containing all the values for the specified enemy.
	*/
	Enemy(Initializer  initializer);

	//! The reduceHP method of the enemy
	/*!
	Damages this enemey, if his hp reaches 0, this enemy will die.
	@param damage The amount of damage dealt to this enemy.
	*/
	virtual void Enemy::reduceHP(int damage);

	//! The update method of the enemy class
	/*!
	Sets the direction of the enemy based on the players position.
	Also checks if the player is in range to perform an attack,
	and checks if the attack isn't on cooldown.
	@param speedModifier changes the speed of the enemy based on the framerate of the game.
	*/
	void Enemy::update(float speedModifier) override;

	//! The draw method of the enemy
	/*!
	Calls the draw function of the animation, to draw the right frame.
	Also checks if this enemy is attacking to see if it is needed to draw the
	attacking animation.
	@param window The window on which everything has to be drawn.
	*/
	void Enemy::draw(sf::RenderWindow & window) const override;

	//! the move method of the enemy.
	/*!
	calculates the direction for the enemy to move towards the player.
	Also checks if the enemy is close to the player. If it is, it keeps its distance.
	This way the enemy doesn't move through the player.
	@param speedModifier changes the speed of the enemy based on the framerate of the game.
	*/
	void Enemy::move(float speedModifier) override;

	//! the setType method of the enemy
	/*!
	sets the values of this enemy to all the values of the initializer.
	Also loads the animation frames for the specified type of enemy.
	@param initializer An object containing all the values for the specified enemy.
	*/
	void Enemy::setType(Initializer initializer);

	//! The standard values for the avarage bully.
	Initializer average{ "Average", 0.9f, 100, true, 20, 60 };

	//! The standard values for the fat bully.
	Initializer fat{ "Fat", 0.7f, 300, true, 20, 60 };

	//! The standard values for the cheerleader bully.
	Initializer cheerleader{ "Cheerleader", 1.3f, 50, true, 20, 100 };

	//! The standard values for the horde bully.
	Initializer horde{ "Horde", 0.7f, 70, true, 20, 70 };

	//! The standard values for the macho bully.
	Initializer macho{ "Macho", 0.8f, 100, true, 40, 30 };


	//! The standard values for the dunken boss bully.
	Initializer dunken{ "Dunken", 1.2f, 3000, true, 65, 60 };
	
	//! The deconstructor of the enemy class.
	/*!
	Deallocates the enemy.
	*/
	~Enemy();


	Initializer & type = average;

	sf::Sprite melee;

	int dmg = 0;

private:
	float hitCooldown = 0;
	bool drawMelee;
	sf::Sprite curSprite;
	sf::Texture tex;
};

