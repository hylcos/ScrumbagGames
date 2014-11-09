#pragma once
#include "../GameObject.h"
class TutorialScreen : public GameObject
{
public:
	TutorialScreen();
	void TutorialScreen::update(float speedModifier) override;
	void TutorialScreen::draw(sf::RenderWindow & window) const override;
	~TutorialScreen();

private :
	sf::Text mainText;
	sf::Text header;
	sf::Text story;
};

