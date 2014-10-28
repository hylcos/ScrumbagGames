#pragma once
#include "Checkbox.h"
class ToggleMusic :
	public Checkbox
{
public:
	ToggleMusic();
	~ToggleMusic();
protected:
	void ToggleMusic::toggle(bool checked) override;
};

