#include "../../stdafx.h"
#include "ToggleMusic.h"
#include "../../SoundController.h"
#include "../../SettingsController.h"


ToggleMusic::ToggleMusic()
{
	checked = (SettingsController::getInstance().getSetting(SettingsController::backgroundMusic) != 0);
	init();
	text.setString("bACKGROUND MUSIC");
}

void ToggleMusic::toggle(bool checked){
	SoundController::getInstance().setBackgroundMusic(checked);
	SettingsController::getInstance().setSetting(SettingsController::setting::backgroundMusic, checked);
}

ToggleMusic::~ToggleMusic()
{
}
