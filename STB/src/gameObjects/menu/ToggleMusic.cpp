#include "../../stdafx.h"
#include "ToggleMusic.h"
#include "../../SoundController.h"


ToggleMusic::ToggleMusic()
{
	checked = true;
}

void ToggleMusic::toggle(bool checked){
	SoundController::getInstance().setBackgroundMusic(checked);
}

ToggleMusic::~ToggleMusic()
{
}
