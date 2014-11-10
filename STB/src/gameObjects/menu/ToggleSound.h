//!The togglesound header file
/*!
This is the header file of the toggle sound class
*/
#pragma once
#include "Checkbox.h"
class ToggleSound :
	public Checkbox
{
public:
	//! The constructor of the toggle sound class
	/*!
	The constructor will check the current value in the settings and set the checkbox accordingly
	*/
	ToggleSound();

	//! The deconstructor of the togglesound class
	/*!
	The defaul deconstructor
	*/
	~ToggleSound();
protected:
	void ToggleSound::toggle(bool checked) override;
};

