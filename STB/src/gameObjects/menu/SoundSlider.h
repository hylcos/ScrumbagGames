//! The sound slider header file
/*!
This is the header file of the sound slider
*/
#pragma once
#include "Slider.h"
class SoundSlider :
	public Slider
{
public:
	//! The sound slider constructor
	/*!
	The constructor will check the saved data of the player to see its setting, and set this slider accordingly
	*/
	SoundSlider();

	//! The update value method of the sound slider class
	/*!
	This method will update the settings of the settingscontroller and the sound controller to the given value
	@param value The given value.
	*/
	void SoundSlider::updateValue(int value) override;

	//! The deconstructor of the sound slider
	/*!
	A default deconstructor
	*/
	~SoundSlider();
};

