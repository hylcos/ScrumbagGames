#include "../../stdafx.h"
#include "SoundSlider.h"
#include "../../SoundController.h"
#include "../../SettingsController.h"


SoundSlider::SoundSlider()
{
	value = std::max(0, std::min(255, SettingsController::getInstance().getSetting(SettingsController::soundVolume)));
}

void SoundSlider::updateValue(int value){
	SoundController::getInstance().setSoundVolume(value);
	SettingsController::getInstance().setSetting(SettingsController::soundVolume, value);
}


SoundSlider::~SoundSlider()
{
}
