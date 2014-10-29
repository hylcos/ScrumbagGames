#include "stdafx.h"
#include "HudController.h"
#include "LevelController.h"
#include "TextureManager.h"
#include "GameController.h"

void HudController::addObject(GameObject * object){
	gameObjectToAdd.push_back(object);
}
void HudController::addObjectFromFactory(GameObject * object){
	gameObjects.push_back(object);
}
void HudController::removeObject(GameObject * object){
	gameObjectToRemove.insert(object);
}
void HudController::removeAllObjects(GameObject * object){
	if (object == nullptr){
		return;
	}
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	delete object;
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}
void HudController::loadHudTextures(){
	rifletex = *TextureManager::getInstance().getTexture("HUDObjecten/rifleWeapon.png");
	riflesprite.setTexture(rifletex);

	pistoltex = *TextureManager::getInstance().getTexture("HUDObjecten/pistolWeapon.png");
	pistolsprite.setTexture(pistoltex);

	swordtex = *TextureManager::getInstance().getTexture("HUDObjecten/swordWeapon.png");
	swordsprite.setTexture(swordtex);

	knifetex = *TextureManager::getInstance().getTexture("HUDObjecten/knifeWeapon.png");
	knifesprite.setTexture(knifetex);

	snipertex = *TextureManager::getInstance().getTexture("HUDObjecten/sniperWeapon.png");
	snipersprite.setTexture(snipertex);

	healthtex = *TextureManager::getInstance().getTexture("HUDObjecten/HealthBar.png");
	healthsprite.setTexture(healthtex);

	ammotex = *TextureManager::getInstance().getTexture("HUDObjecten/AmmoBar.png");
	ammosprite.setTexture(ammotex);

	timetex = *TextureManager::getInstance().getTexture("HUDObjecten/Timer.png");
	timesprite.setTexture(timetex);
	
	weapontex = *TextureManager::getInstance().getTexture("HUDObjecten/ExtraWeapon.png");
	weaponsprite1.setTexture(weapontex);
	weaponsprite2.setTexture(weapontex);

	buffstex = *TextureManager::getInstance().getTexture("HUDObjecten/BuffsBar.png");
	buffssprite.setTexture(buffstex);
}
void HudController::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;
	
	font.loadFromFile("Resources/Fonts/Coalition_v2.ttf");
    ammotext.setFont(font);
	ammotext.setCharacterSize(20);
	ammotext.setColor(sf::Color(119,108,108));
	ammotext.setPosition(456, 431);

	timetext.setFont(font);
	timetext.setCharacterSize(20);
	timetext.setColor(sf::Color(119, 108, 108));
	timetext.setPosition(278, 18);
	timetext.setString("00:00");

	loadHudTextures();

	timesprite.setOrigin(timetex.getSize().x / 2.0f, timetex.getSize().y / 2.0f);
	weaponsprite1.setOrigin(weapontex.getSize().x / 2.0f, weapontex.getSize().y / 2.0f);
	weaponsprite2.setOrigin(weapontex.getSize().x / 2.0f, weapontex.getSize().y / 2.0f);

	timesprite.setPosition(sf::Vector2f(320,30));
	healthsprite.setPosition(sf::Vector2f(20, 405));
	ammosprite.setPosition(sf::Vector2f(444, 410));

	weaponsprite1.setPosition(sf::Vector2f(595, 380));
	weaponsprite2.setPosition(sf::Vector2f(595, 330));
	ammoForeGround.setPosition(sf::Vector2f(455, 431));
	healthForeGround.setPosition(sf::Vector2f(35, 440));

	healthForeGround.setFillColor(sf::Color::Red);
	ammoForeGround.setFillColor(sf::Color::Yellow);
	sf::Clock::Clock();

}

void HudController::step(sf::RenderWindow & window){
	float speedModifier = 60 / GameController::getInstance().getFPS();
	sf::View hudView;
	hudView.setCenter(static_cast<sf::Vector2f>(window.getSize()) / 2.0f);
	hudView.setSize(static_cast<sf::Vector2f>(window.getSize()));
	//hudView.setCenter(sf::Vector2f(0.0f, 0.0f));
	window.setView(hudView);


	for (GameObject* obj : gameObjects){
		obj->update(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->move(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->draw(window);
	}
	if (LevelController::getInstance().getPlayer() != nullptr){
		healthForeGround.setSize(sf::Vector2f(static_cast<float>(LevelController::getInstance().getPlayer()->getHp()* 1.5) , 15));
		ammoForeGround.setSize(sf::Vector2f(static_cast<float>(LevelController::getInstance().getPlayer()->getAmmo()), 28));
		ammotext.setString(LevelController::getInstance().getPlayer()->getSelectedWeapon()->getAmmoString());
	}
	else {
		healthForeGround.setSize(sf::Vector2f(150, 15));
		ammoForeGround.setSize(sf::Vector2f(100, 28));
	}


	window.draw(weaponsprite1);
	window.draw(weaponsprite2);
	window.draw(ammosprite);
	window.draw(healthsprite);
	window.draw(healthForeGround);
	window.draw(ammoForeGround);
	window.draw(timesprite);
	window.draw(ammotext);
	window.draw(timetext);
}
void HudController::prepareForNextLevel(){
	gameObjects.clear();
}

sf::Vector2f HudController::getMousePos(){
	return sf::Vector2f(sf::Mouse::getPosition(GameController::getInstance().getWindow())) - sf::Vector2f(GameController::getInstance().getWindow().getSize().x / 2.0f, GameController::getInstance().getWindow().getSize().y / 2.0f)+sf::Vector2f{ 320, 240 };
}
