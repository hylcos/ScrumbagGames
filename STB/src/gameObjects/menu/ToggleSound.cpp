#include "../../stdafx.h"
#include "ToggleSound.h"
#include "../../SettingsController.h"


ToggleSound::ToggleSound()
{
	text.setString("sOUNDS");
}

void ToggleSound::toggle(bool checked){
	SettingsController::getInstance().setSetting(SettingsController::sounds,checked);
}

ToggleSound::~ToggleSound()
{
}
