#include "../../stdafx.h"
#include "Checkbox.h"
#include "../../TextureManager.h"


Checkbox::Checkbox()
{
	texChecked = TextureManager::getInstance().getTexture("menuObjecten/CheckedOption.png");
	texUnchecked = TextureManager::getInstance().getTexture("menuObjecten/UncheckedOption.png");
	sprite.setTexture(*texUnchecked, true);
	sprite.setOrigin(static_cast<sf::Vector2f>(texChecked->getSize()) / 2.0f);
}

void Checkbox::update(float speedModifier){
	sprite.setPosition(position);
	Clickable::update();
}

void Checkbox::draw(sf::RenderWindow & window) const{
	window.draw(sprite);
}

sf::FloatRect Checkbox::getBounds(){
	return sprite.getGlobalBounds();
}

void Checkbox::setToggleAction(void(*function)(bool checked)){
	this->function = function;
}

void Checkbox::click(){
	checked = !checked;
	sprite.setTexture((checked ? *texChecked : *texUnchecked), true);
	if (function == nullptr){
		return;
	}
	(function)(checked);
}

Checkbox::~Checkbox()
{
}
