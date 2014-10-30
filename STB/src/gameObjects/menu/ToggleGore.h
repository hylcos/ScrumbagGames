#pragma once
#include "Checkbox.h"
class ToggleGore :
	public Checkbox
{
public:
	ToggleGore();
	~ToggleGore();
private:
	void ToggleGore::toggle(bool checked) override;
};

