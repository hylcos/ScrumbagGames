#include "stdafx.h"
#include "GameController.h"
#include "LevelController.h"
#include "Factory.h"
#include "GameObjects/Powerup.h"
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
void LevelController::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;
	background.loadFromFile("Resources/Images/Background.jpg");
	backgroundOverlay.loadFromFile("Resources/Images/BackgroundOverlay.jpg");

	pauseOverlay.loadFromFile("Resources/Images//PauseMenuOverlay.png");
	pauseSprite.setTexture(pauseOverlay, true);

	backgroundSprite.setTexture(background, true);
	backgroundSpriteOverlay.setTexture(backgroundOverlay, true);

	mainView.setSize(sf::Vector2f(640, 480));
	mainView.setCenter(320, 240);
}

LevelController::Initializer::Initializer(std::string name)
{
	Initializer::name = name;
}

void LevelController::goToNextLevel(LevelController::Initializer * initializer){
	nextLevel = initializer;
}

void LevelController::startLevel(LevelController::Initializer initializer){

	Factory factory;
	int settings = factory.loadLevel(initializer.name);
	terrorLevel = settings & 255;
	bool random = ((settings & factory.random) == factory.random);
	player = nullptr;
	for (GameObject* obj : gameObjects){
		if (random){
			obj->setRandomness(terrorLevel);
		}
		if (obj->getType() == GameObject::player) {
			player = dynamic_cast<Player*>(obj);
		}
		if (obj->getType() == GameObject::particleManager) {
			particleManager = dynamic_cast<ParticleManager*>(obj);
		}
	}

	/*
	Powerup* pu = new Powerup(sf::Vector2f{ 250, 250 }, 6);
	pu->setType(&pu->puFullHealth);
	addObjectFromFactory(pu);

	pu = new Powerup(sf::Vector2f{ 200, 250 });
	pu->setType(&pu->puSprint);
	addObjectFromFactory(pu);

	pu = new Powerup(sf::Vector2f{ 150, 250 }, 4);
	pu->setType(&pu->puFullHealth);
	addObjectFromFactory(pu);

	pu = new Powerup(sf::Vector2f{ 100, 250 }, 3);
	pu->setType(&pu->puSprint);
	addObjectFromFactory(pu);*/


}

void LevelController::step(float fps, sf::RenderWindow & window){
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !pausedPressed && player != nullptr){
		paused = !paused;
		pausedPressed = true;
	} 
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
		pausedPressed = false;
	}
		float speedModifier = 60 / fps;
		for (GameObject* obj : gameObjectToAdd){
			gameObjects.push_back(obj);
		}
		gameObjectToAdd.clear();

		for (GameObject* obj : gameObjectToRemove){
			LevelController::removeAllObjects(obj);
		}
		gameObjectToRemove.clear();
		if (!paused){
			for (GameObject* obj : gameObjects){
				obj->update(speedModifier);
			}

			for (GameObject* obj : gameObjects){
				obj->move(speedModifier);
			}
			if (timeToNextEnemySpawn <= 0 && player != nullptr){
				sf::Vector2f enemyPosition(0,0);
				int random = rand() % 360;
				float radius = random * PI / 180;
				enemyPosition.x = player->getPosition().x + cos(radius) * 640;
				enemyPosition.y = player->getPosition().y + sin(radius) * 480;
				
				Enemy * e = new Enemy();
				switch (rand() % 4){
					case 0: e->setType(e->average); break;
					case 1: e->setType(e->fat); break;
					case 2: e->setType(e->cheerleader); break;
					case 3: e->setType(e->macho); break;
				}
				e->setPosition(enemyPosition);
				addObject(e);
				timeToNextEnemySpawn = enemySpawnTime;
			}
			else {
				timeToNextEnemySpawn -= speedModifier;
			}
		}
		//window.clear(sf::Color::White);

		window.setView(mainView);

		window.draw(backgroundSprite);
		backgroundSpriteOverlay.setColor(sf::Color{ 255, 255, 255, terrorLevel });
		window.draw(backgroundSpriteOverlay);

		if (player != nullptr){
			setMainView(player->getPosition());
			sf::Vector2f pos = getMousePos() - player->getPosition();
			player->setRotation(atan2(pos.y, pos.x) * 180 / 3.14159265358979323846f + 90);
		}
		else{
			viewMovement.x = std::max(-1.0f, std::min(1.0f, viewMovement.x + ((rand() % 11) - (4.8f + (mainView.getCenter().x < 640 ? 0.0f : 0.4f))) / 10000.0f));
			viewMovement.y = std::max(-1.0f, std::min(1.0f, viewMovement.y + ((rand() % 11) - (4.8f + (mainView.getCenter().y < 480 ? 0.0f : 0.4f))) / 10000.0f));
			moveMainView(viewMovement*speedModifier*10.0f);
		}

		for (GameObject* obj : gameObjects){
			obj->draw(window);
		}
	
	
	if(paused) {
		backToMenu.setPosition(sf::Vector2f(mainView.getCenter().x,mainView.getCenter().y+60));
		backToMenu.update(speedModifier);
		
		restart.setPosition(mainView.getCenter());
		restart.update(speedModifier);
		
		resume.setPosition(sf::Vector2f(mainView.getCenter().x, mainView.getCenter().y - 60));
		resume.update(speedModifier);

		window.draw(pauseSprite);
		backToMenu.draw(window);
		restart.draw(window);
		resume.draw(window);
	}
	if (nextLevel != nullptr)
	{
		paused = false;
		stopLevel();
		HudController::getInstance().prepareForNextLevel();
		startLevel(*nextLevel);
		nextLevel = nullptr;
	}
}

void LevelController::stopLevel(){
	for (GameObject* obj : gameObjects){
		delete obj;
	}
	gameObjects.clear();
}

sf::Vector2f LevelController::getMousePos(){
	return sf::Vector2f(sf::Mouse::getPosition(GameController::getInstance().getWindow())) - sf::Vector2f(GameController::getInstance().getWindow().getSize().x / 2.0f, GameController::getInstance().getWindow().getSize().y / 2.0f) + mainView.getCenter();
}

const std::vector< GameObject* > LevelController::getGameObjects(){
	return gameObjects;
}

void LevelController::moveMainView(sf::Vector2f pos){
	moveMainView(pos.x, pos.y);
}
void LevelController::moveMainView(float x, float y){
	setMainView(mainView.getCenter().x + x, mainView.getCenter().y + y);
}

void LevelController::setMainView(sf::Vector2f pos){
	setMainView(pos.x, pos.y);
}

void LevelController::setMainView(float x, float y){
	mainView.setCenter(std::min(std::max(x, 320.0f), 1280.0f - 320.0f), std::min(std::max(y, 240.0f), 960.0f - 240.0f));
}

void LevelController::addObject(GameObject * object){
	gameObjectToAdd.push_back(object);
}
void LevelController::addObjectFromFactory(GameObject * object){
	gameObjects.push_back(object);
}
void LevelController::removeObject(GameObject * object){
	gameObjectToRemove.insert(object);
}
void LevelController::removeAllObjects(GameObject * object){
	if (object == nullptr){
		return;
	}
	std::vector<GameObject*>::iterator position = std::find(gameObjects.begin(), gameObjects.end(), object);
	delete object;
	if (position != gameObjects.end()) // == vector.end() means the element was not found
		gameObjects.erase(position);
}

Player * LevelController::getPlayer(){
	return player;
}

ParticleManager * LevelController::getParticleManager(){
	return particleManager;
}

void LevelController::setPaused(){
	paused = !paused;
}
/*
LevelController::~LevelController()
{
for (GameObject* obj : gameObjects){
obj->~GameObject();
}
}*/
