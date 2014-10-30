#pragma once
#include "Slider.h"
class MusicSlider :
	public Slider
{
public:
	MusicSlider();
	void MusicSlider::updateValue(int value) override;
	~MusicSlider();
};

