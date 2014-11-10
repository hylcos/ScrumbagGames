#pragma once
#include "Slider.h"
class MusicSlider :
	public Slider
{
public:
	//! The MusicSlider constructor
	/*!
	The constructor will check the saved data of the player to see its setting, and set this slider accordingly
	*/
	MusicSlider();

	//! The update value method of the MusicSlider class
	/*!
	This method will update the settings of the settingscontroller and the sound controller to the given value
	@param value The given value.
	*/
	void MusicSlider::updateValue(int value) override;


	//! The deconstructor of the MusicSlider
	/*!
	A default deconstructor
	*/
	~MusicSlider();
};

