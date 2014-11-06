#include "../../stdafx.h"
#include "TutorialScreen.h"
#include "../../GameController.h"

TutorialScreen::TutorialScreen()
{
	header.setString("Shoot The Bully\n\n\n\n\n\nCONTROLS");
	header.setFont(*GameController::getInstance().getFont());
	header.setColor(sf::Color::Black);

	std::string timeLine;
	timeLine += "Het spel gaat over Marcel Ramsbottom, \nhij is een jongen die  op school wordt gepest, ";
	timeLine += "\nop een dag neemt hij het besluit om er wat tegen te doen. \n\n";
	timeLine += "De volgende dag op school rent hij op de grootste\npestkop af en probeert hem te slaan \n";
	timeLine += "Hij houdt dit tegen en duwt Marcel tegen een betonnen \nmuur aan";
	timeLine += "\n\nMarcel voelt bloed lopen en verliest het bewust zijn ";

	story.setString(timeLine);
	story.setCharacterSize(13);
	story.setFont(*GameController::getInstance().getFont());
	story.setColor(sf::Color::Black);

	std::string controls;
	controls += "WSAD: Lopen in verschillende Richtingen \n";
	controls += "Muis Positie: richting van kogels veranderen\n";
	controls += "R: Reloaden\n";
	controls += "1, 2, 3: Wisselen tussen wapens\n\n";
	controls += "Door het doden van Vijanden kan je geld verdienen\nen dit kan je uitgeven in de winkel tussen rondes in.\n\n";
	controls += "Elke upgrade heeft 5 levels:\nelk nieuwe upgrades kost 100 euro meer dan de vorige";

	mainText.setString(controls);
	mainText.setCharacterSize(13);
	mainText.setFont(*GameController::getInstance().getFont());
	mainText.setColor(sf::Color::Black);
}

void TutorialScreen::update(float speedModifier) {
	header.setPosition(position);
	story.setPosition(sf::Vector2f(position.x, position.y + 30));
	mainText.setPosition(sf::Vector2f(position.x, position.y + 210));
}

void TutorialScreen::draw(sf::RenderWindow & window) const {
	window.draw(header);
	window.draw(story);
	window.draw(mainText);
}
TutorialScreen::~TutorialScreen()
{
}
