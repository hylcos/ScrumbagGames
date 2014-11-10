//! The toggle gore header file
/*!
This is the header file of the toggle gore class
*/
#pragma once
#include "Checkbox.h"
class ToggleGore :
	public Checkbox
{
public:
	//! The constructor of the toggle gore class
	/*!
	The constructor will check the saved data of the user for the toggle gore setting, and set its checkbox accordingly.
	*/
	ToggleGore();

	//! The deconstructor of the toggle gore class
	/*!
	The defaul deconstructor
	*/
	~ToggleGore();
private:
	void ToggleGore::toggle(bool checked) override;
};

