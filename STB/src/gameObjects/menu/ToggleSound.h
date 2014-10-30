#pragma once
#include "Checkbox.h"
class ToggleSound :
	public Checkbox
{
public:
	ToggleSound();
	~ToggleSound();
protected:
	void ToggleSound::toggle(bool checked) override;
};

