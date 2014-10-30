#include "../../stdafx.h"
#include "MusicSlider.h"
#include "../../SettingsController.h"
#include "../../SoundController.h"


MusicSlider::MusicSlider()
{
	value = std::max(0, std::min(255, SettingsController::getInstance().getSetting(SettingsController::backgroundMusicVolume)));
}

void MusicSlider::updateValue(int value){
	SoundController::getInstance().setBackgroundMusicVolume(value); 
	SettingsController::getInstance().setSetting(SettingsController::backgroundMusicVolume, value);
}

MusicSlider::~MusicSlider()
{
}
