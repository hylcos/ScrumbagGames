#pragma once
#include "Animation.h"
#include "SFML\Graphics.hpp"
#include "ParticleEmitter.h"
#include "Weapon.h"
#include "Gun.h"

#include "Collision.h"
class Player : public Animation, ParticleEmitter
{
public:
	//! Constructor method for Player
	/*!
	The constructor of Player gets the needed textures from the texture manager.
	And sets the Animation with these Textures.
	It sets the begins weapons for the player, which are the Dagger,Pistol,Shotgun
	And Configures the Particals that have to spawn when the player walks
	*/
	Player();
	
	//! The Move method for Player
	/*!
	Checks for every button in the Action struct if it is being pressed if so it's added 
	to the new Position.
	Then there will be checks if the player actually can walk in that direction. If there
	isn't anything in that direction where the player can't walk through.
	If that isn't the case the New Position whill be the new Position
	@param speedModifier the frame rate on which the speed of the player must be calculated on
	*/
	void Player::move(float speedModifier) override;
	//! The Move method for Player
	/*!
	Calls Animation::update, that will set the position and rotation and counts down to the new frame
	sets the new position and Rotation of the selected gun
	Also Checks if any button is pressed that will reload, fire or change a Weapon
	It Also will keep track of all the different powerups, when there time exceeds
	@param speedModifier the frame rate on which the time for the powerups must be calculated on
	*/
	void Player::update(float speedModifier) override;
	//! The Draw method of the Player
	/*!
	Draws the current sprite of the Player and the selected weapon on the Screen
	@param window the screen on which the Player and selected weapon should be drawn.
	*/
	void Player::draw(sf::RenderWindow & window) const override;

	//! The setRotation method of the Player
	/*!
	Sets the new Rotation of the player and Animation
	@param rotation the new rotation for the player, weapons and animation
	*/
	void Player::setRotation(float rotation) override;


	//! The getHp method of the Player
	/*!
	@return the current HP of the player
	*/
	int Player::getHp();
	//! The reduceHP method of the Player
	/*!
	reduces the current Hp and checks if the player is dead
	@param the number of damage that has to be taken of the HP
	*/
	void Player::reduceHP(int damage);

	//! The addMoney method of the Player
	/*!
	couts up the current money
	@param the number of Money that needs to be added
	*/
	void Player::addMoney(int money);
	//! The setMoney method of the Player
	/*!
	sets the current Money to a new Value
	@param the number of Money that the current moeny has to been set to
	*/
	void Player::setMoney(int money);
	//! The getMoney method of the Player
	/*!
	@return the current Money the Player has
	*/
	int Player::getMoney();

	//! The setNextRound method of the Player
	/*!
	sets if the player has defeated the boss and the GoToNextRound Screen has to fade in
	@param value true: if Round completed, false: if Round isn't complete
	*/
	void Player::setNextRound(bool value);
	//! The getNextRound method of the Player
	/*!
	@return true: if Round completed, false: if Round isn't complete
	*/
	bool Player::getNextRound();
	
	//! The setWeapons method of the Player
	/*!
	Sets the new Weapons for the player
	@param weapon1 First Weapon
	@param weapon2 Second Weapon
	@param weapon3 Third Weapon
	*/
	void Player::setWeapons(Weapon * weapon1, Weapon * weapon2, Weapon * weapon3);
	//! The getSelectedWeapon method of the Player
	/*!
	@return the Weapon which is selected at this current moment
	*/
	Weapon * Player::getSelectedWeapon();
	//! The getWeapons method of the Player
	/*!
	Return one of the selected weapons
	@param value the number of which of the three weapons has to be returned
	@return the Weapon which corresponds with the given value
	*/
	Weapon * Player::getWeapons(int value);

	//! gets the Size of the Table
	/*!
	Gets the size of the sprite and returns this.
	@return the size of the sprite so they can be compared with
	different objects
	*/
	sf::Vector2u Player::getSize() override;
	
	//! The getgameOver method of the Player
	/*!
	@return true: if HP <= 0, false: if HP > 0
	*/
	bool Player::getgameOver();

	//! The doubleSpeed method of the Player
	/*!
	Sets the speed of player to 5 and sets a timer to indicate when the Powerup has to stop
	*/
	void Player::doubleSpeed();
	//! The fullHealth method of the Player
	/*!
	sets the Hp of the Player to 100
	*/
	void Player::fullHealth();

	//! The deconstructor  of a Player
	/*!

	*/
	~Player();
private:

	sf::Texture tex1, tex2, tex3;
	sf::Sprite curSprite;
	float rotation = 0.0;
	float doubleSpeedTimer, invincibleTimer, gameOverTimer;
	int curWeapon = 0;
	bool invincible, gameOver = false;
	Weapon * selectedWeapons[3];
	bool isOnTable = false;
	int hp = 100;
	int speed = 1;
	int framesTillNextParticle = 0;
	int walkSound = 0;
	float toNextWalkSound = 0;
	int money = 0;
	bool nextRound = false;
};

