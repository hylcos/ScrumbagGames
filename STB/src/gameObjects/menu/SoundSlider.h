#pragma once
#include "Slider.h"
class SoundSlider :
	public Slider
{
public:
	SoundSlider();
	void SoundSlider::updateValue(int value) override;
	~SoundSlider();
};

