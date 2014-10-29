#include "../../stdafx.h"
#include "Checkbox.h"
#include "../../TextureManager.h"
#include "..\..\GameController.h"
#include "../../SettingsController.h"


Checkbox::Checkbox()
{
	checked = (SettingsController::getInstance().getSetting(SettingsController::setting::backgroundMusic) != 0);

	texChecked = TextureManager::getInstance().getTexture("menuObjecten/CheckedOption.png");
	texUnchecked = TextureManager::getInstance().getTexture("menuObjecten/UncheckedOption.png");
	sprite.setTexture((checked ? *texChecked : *texUnchecked), true);
	sprite.setOrigin(static_cast<sf::Vector2f>(texChecked->getSize()) / 2.0f);
	text.setString("You are not supposed to see this...");
	text.setFont(*(GameController::getInstance().getFont()));
	text.setCharacterSize(15);
	text.setOrigin(0.0f, text.getCharacterSize() / 2.0f);
	text.setColor(sf::Color::Black);
}

void Checkbox::update(float speedModifier){
	sprite.setPosition(position);
	text.setPosition(position + sf::Vector2f{ 16, 0 });
	Clickable::update();
}

void Checkbox::draw(sf::RenderWindow & window) const{
	window.draw(text);
	window.draw(sprite);
}

sf::FloatRect Checkbox::getBounds(){
	return sprite.getGlobalBounds();
}

void Checkbox::toggle(bool checked){}

void Checkbox::click(){
	checked = !checked;
	sprite.setTexture((checked ? *texChecked : *texUnchecked), true);
	SettingsController::getInstance().setSetting(SettingsController::setting::backgroundMusic, checked);
	toggle(checked);
}

Checkbox::~Checkbox()
{
}
