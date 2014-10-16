//!  The Animation Class
/*!
This Class is the parent class for all animated game objects. It inherits most of the game object class.
*/

#pragma once
#include "GameObject.h"
//! An allocation for a texture.
/*!
This variable is used instead of a null pointer.
For some reasen the program won't run without it.
*/
static sf::Texture * NUL = new sf::Texture{};

class Animation : public GameObject
{
public:
	//!  The Constructor
	/*!
	Just a default constructor, does nothing in particular.
	*/
	Animation(gameObjectType type = unspecified);

	//!  SetTextures sets the textures used in this animation.
	/*!
	Set the textures that have to be used in this animation.
	The textures will be place in sequential order. Max. 8 textures.
	\param tex1 the first texture where the animation starts.
	\param tex2-tex8 all the other textures of which the animation consists.
	*/
	void setTextures(sf::Texture & tex1, sf::Texture & tex2 = *NUL, sf::Texture & tex3 = *NUL, sf::Texture & tex4 = *NUL,
		sf::Texture & tex5 = *NUL, sf::Texture & tex6 = *NUL, sf::Texture & tex7 = *NUL, sf::Texture & tex8 = *NUL);

	//!  Sets the current texture to the next one
	/*!
	First this method checks if the current texture is the last one,
	if it is it will set the first texture from the array to the current one.
	If it isn't, it will set the next texture from the array to the current one.
	*/
	void Animation::next() override;

	//! Updates the texture of the animation
	/*!
	Updates the current texture of the animation to the right one based on the time elapsed.
	\param speedModifier isn't really used in this method, but is there because of the override.
	*/
	void Animation::update(float speedModifier) override;

	//! Draw draws the current texture on the window.
	/*!
	Gets the current sprite and draws it on the screen given in the parameters.
	\param window is the window in which the whole game is displayed
	*/
	void Animation::draw(sf::RenderWindow & window) const override;

	void Animation::move(float speedModifier) override;

	//! setRotation sets the rotation of the animation.
	/*!
	\param rotation the amount to which the local variable rotation should be set.
	*/
	void Animation::setRotation(float rotation) override;

	//! getCurrentAnimation returns the current sprite.
	/*!
	\return The current sprite that would be drawn on the screen.
	*/
	sf::Sprite *  Animation::getCurrentAnimation();

	//! GetBounds gives the bounds of the animation.
	/*!
	\return The bounds of the animation in its current state.
	*/
	sf::FloatRect Animation::getBounds() override;

	//! The destructor of the animation object.
	/*!
	Deletes the animation when it is no longer needed.
	*/
	~Animation();
private:
	//! The Array with textures.
	/*!
	In this array all the different textures that are used for the animation are saved.
	*/
	sf::Texture  tex[8];

	//! The current sprite.
	/*!
	The sprite is what is drawn on the screen.
	*/
	sf::Sprite curSprite;

	//! The current texture drawn on the screen.
	/*!
	Indicates which texture from the array is currently used.
	*/
	int current = 0;
protected:
	//! The rotation of the texture.
	/*!
	Indicates how much the animation should be rotated.
	*/
	float rotation = 0.0;

	//! How much time has elapsed.
	/*!
	If enough time has elapsed the next texture should be drawn,
	the time elapsed is indicated by the toNext integer.
	*/
	float toNext = 0.0;
};

