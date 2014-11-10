//! The toggle music header file
/*!
This is the header file of the toggle music class
*/
#pragma once
#include "Checkbox.h"
class ToggleMusic :
	public Checkbox
{
public:
	//! The constructor of the toggle music class
	/*!
	This constructor will check the saved data for the current state of this setting, and set the checkbox accordingly
	*/
	ToggleMusic();

	//! The deconstructor of the toggle music class
	/*!
	The defaul deconstructor
	*/
	~ToggleMusic();
protected:
	void ToggleMusic::toggle(bool checked) override;
};

