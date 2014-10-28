#pragma once
#include "..\Clickable.h"
class Options :
	public Clickable
{
public:
	Options();
	void Options::update(float speedModifier) override;
	void Options::draw(sf::RenderWindow & window) const override;
	void Options::click() override;
	sf::FloatRect Options::getBounds() override;
	~Options();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

