#include "../../stdafx.h"
#include "ToggleMusic.h"
#include "../../SoundController.h"


ToggleMusic::ToggleMusic()
{
	text.setString("bACKGROUND MUSIC");
}

void ToggleMusic::toggle(bool checked){
	SoundController::getInstance().setBackgroundMusic(checked);
}

ToggleMusic::~ToggleMusic()
{
}
