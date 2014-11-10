#include "../../stdafx.h"
#include "ToggleGore.h"
#include "../../SettingsController.h"

ToggleGore::ToggleGore()
{
	checked = (SettingsController::getInstance().getSetting(SettingsController::gore) != 0);
	init();
	text.setString("gORE");
}

void ToggleGore::toggle(bool checked){
	SettingsController::getInstance().setSetting(SettingsController::gore, checked);
}

ToggleGore::~ToggleGore()
{
}
