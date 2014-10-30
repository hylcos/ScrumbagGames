#include "../../stdafx.h"
#include "ToggleSound.h"
#include "../../SettingsController.h"


ToggleSound::ToggleSound()
{
	checked = (SettingsController::getInstance().getSetting(SettingsController::sounds) != 0);
	init();
	text.setString("sOUNDS");
}

void ToggleSound::toggle(bool checked){
	SettingsController::getInstance().setSetting(SettingsController::sounds,checked);
}

ToggleSound::~ToggleSound()
{
}
