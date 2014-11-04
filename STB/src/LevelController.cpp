#include "stdafx.h"
#include "LevelController.h"
#include <SFML\Graphics.hpp>


LevelController::Initializer LEVELS[5];
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
	LEVELS[0] = LEVEL_ONE;
	LEVELS[1] = LEVEL_TWO;
	LEVELS[2] = LEVEL_THREE;
	LEVELS[3] = LEVEL_FOUR;
	LEVELS[4] = LEVEL_FIVE;
	enemySpawnTime = 240;
}

LevelController::Initializer::Initializer(std::string name)
{
	Initializer::name = name;
}
LevelController::Initializer::Initializer(){}

void LevelController::setZoom(float f){
	targetZoom = f;
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
			if (&player2 != nullptr){
				player->setWeapons(player2.getWeapons(1), player2.getWeapons(2), player2.getWeapons(3));
				player->setMoney(player2.getMoney());
			}
			player2 = *player;
		}
		if (obj->getType() == GameObject::particleManager) {
			particleManager = dynamic_cast<ParticleManager*>(obj);
		}
	}

}

void LevelController::step(float fps, sf::RenderWindow & window){
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !pausedPressed && player != nullptr){
		paused = !paused;
		pausedPressed = true;
	} 
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
		pausedPressed = false;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F11) )) {
		LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
	}
		float speedModifier = 60 / fps;

		mainView.setSize(sf::Vector2f(curZoom * 640, curZoom * 480));
		curZoom = curZoom * 0.99f + targetZoom * 0.01f;

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
				
				Enemy * e = new Enemy();

				switch (rand() % 4){
					case 0: e->setType(e->average); break;
					case 1: e->setType(e->fat); break;
					case 2: e->setType(e->cheerleader); break;
					case 3: e->setType(e->macho); break;
				}
				int random = rand() % 360;
				float radius = random * PI / 180;
				enemyPosition.x = player->getPosition().x + cos(radius) * 640;
				enemyPosition.y = player->getPosition().y + sin(radius) * 480;
				if (enemyPosition.y > 960){
					enemyPosition.y -= 480 * 1.5;
				} else if (enemyPosition.y > 0){
					enemyPosition.y += 480 * 1.5;
				} 
				if (enemyPosition.x > 1280){
					enemyPosition.x -= 640 * 1.5;
				} else if (enemyPosition.x < 0){
					enemyPosition.x += 640 * 1.5;
				}
				
				e->setPosition(enemyPosition);
				enemyPosition = sf::Vector2f{ 0, 0 };
				addObject(e);
				timeToNextEnemySpawn = enemySpawnTime;
			}
			else {
				timeToNextEnemySpawn -= speedModifier;
			}
		}
		/*if (player != nullptr){
			if (enemyPosition.x < 32 || enemyPosition.x > 1248){
				int random = rand() % 360;
				float radius = random * PI / 180;
				enemyPosition.x = player->getPosition().x + cos(radius) * 640;
			}
			if (enemyPosition.y < 32 || enemyPosition.y > 934){
				int random = rand() % 360;
				float radius = random * PI / 180;
				enemyPosition.y = player->getPosition().y + sin(radius) * 480;
			}
		}*/
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
		if (player != nullptr)
			player2 = *player;
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
	gameObjectToRemove.clear();
	gameObjectToAdd.clear();
}

sf::Vector2f LevelController::getMousePos(){
	return sf::Vector2f(sf::Mouse::getPosition(GameController::getInstance().getWindow())) - sf::Vector2f(GameController::getInstance().getWindow().getSize())/2.0f + mainView.getCenter();
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
	mainView.setCenter(std::min(std::max(x, curZoom *320.0f), 1280.0f - curZoom *320.0f), std::min(std::max(y, curZoom *240.0f), 960.0f - curZoom *240.0f));
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
Player * LevelController::getPlayer2(){
	return &player2;
}

ParticleManager * LevelController::getParticleManager(){
	return particleManager;
}

void LevelController::setPaused(){
	paused = !paused;
}
void LevelController::goToNextRound(){
	if (curLevel < 4){
		curLevel++;
		goToNextLevel(&LEVELS[curLevel]);
	}
	else{
		goToNextLevel(&MENU_MAIN);
	}
}
/*
LevelController::~LevelController()
{
for (GameObject* obj : gameObjects){
obj->~GameObject();
}
}*/
