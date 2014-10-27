#pragma once
#include "..\Clickable.h"
class MainMenu :
	public Clickable
{
public:
	MainMenu();	
	void MainMenu::update(float speedModifier) override;
	void MainMenu::draw(sf::RenderWindow & window) const override;
	void MainMenu::click() override;
	sf::FloatRect MainMenu::getBounds() override;

	~MainMenu();
private:
	sf::Texture * tex;
	sf::Sprite sprite;
};

