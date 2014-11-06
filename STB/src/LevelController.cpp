#include "stdafx.h"
#include "LevelController.h"
#include <SFML\Graphics.hpp>
#include "gameObjects\WeaponManager.h"

LevelController::Initializer LEVELS[5];
void LevelController::load()
{
	if (isLoaded){
		return;
	}
	isLoaded = true;

	backToMenu.setOnHud(true);
	restart.setOnHud(true);
	resume.setOnHud(true);
	backToMenu.setPosition(sf::Vector2f{ 320, 240 } +sf::Vector2f{ 0, 60 });
	restart.setPosition(sf::Vector2f{ 320, 240 });
	resume.setPosition(sf::Vector2f{ 320, 240 } +sf::Vector2f{ 0, -60 });

	background.loadFromFile("Resources/Images/Background.jpg");
	backgroundOverlay.loadFromFile("Resources/Images/BackgroundOverlay.jpg");

	pauseOverlay.loadFromFile("Resources/Images//PauseMenuOverlay.png");
	pauseSprite.setTexture(pauseOverlay, true);

	gameOverTexture.loadFromFile("HUDObjecten/GameOver.png");
	gameOverSprite.setTexture(gameOverTexture, true);

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
	gameOverTimer = 0.f;
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

void LevelController::spawnEnemies(float speedModifier){
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
		}
		else if (enemyPosition.y > 0){
			enemyPosition.y += 480 * 1.5;
		}
		if (enemyPosition.x > 1280){
			enemyPosition.x -= 640 * 1.5;
		}
		else if (enemyPosition.x < 0){
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

void LevelController::step(float fps, sf::RenderWindow & window){
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && !pausedPressed && player != nullptr){
		paused = !paused;
		pausedPressed = true;
	}
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
		pausedPressed = false;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F11))) {
		LevelController::getInstance().goToNextLevel(&LevelController::getInstance().SHOP);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F1))) {
		LevelController::getInstance().getPlayer()->addMoney(1000);
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

	window.setView(mainView);

	window.draw(backgroundSprite);
	backgroundSpriteOverlay.setColor(sf::Color{ 255, 255, 255, terrorLevel });
	window.draw(backgroundSpriteOverlay);

	if (nextLevel != nullptr)//Go to next level if nextLevel != nullptr
	{
		paused = false;
		if (player != nullptr)
			player2 = *player;
		stopLevel();
		HudController::getInstance().prepareForNextLevel();

		startLevel(*nextLevel);
		nextLevel = nullptr;
	}

	if (paused) {//paused
		backToMenu.update(speedModifier);

		restart.update(speedModifier);

		resume.update(speedModifier);


		window.setView(mainView);
		for (GameObject* obj : gameObjects){
			obj->draw(window);
		}

		window.setView(HudController::getInstance().getHudView());
		window.draw(pauseSprite);
		backToMenu.draw(window);
		restart.draw(window);
		resume.draw(window);
		return;
	}

	if (player != nullptr){//gameOver
		if (LevelController::getInstance().getPlayer()->getgameOver()){
			for (GameObject* obj : gameObjects){
				obj->draw(window);
			}

			window.setView(HudController::getInstance().getHudView());
			sf::RectangleShape rect{ sf::Vector2f{ 640, 480 } };
			rect.setPosition(0, 0);
			rect.setFillColor(sf::Color::Color(25, 25, 25, static_cast<sf::Uint8>(std::min(255.f, gameOverTimer))));
			window.draw(rect);


			sf::Text text;
			text.setString("gAME OVER");
			text.setFont(*GameController::getInstance().getFont());
			//text.setCharacterSize(60);
			text.setOrigin(sf::Vector2f{ text.getLocalBounds().width, text.getLocalBounds().height } / 2.f);
			text.setPosition(320, 240);
			text.setColor(sf::Color::Color(255, 0, 0, static_cast<sf::Uint8>(std::min(255.f, gameOverTimer*2))));
			window.draw(text);

			if (gameOverTimer > 200.f){
				backToMenu.update(speedModifier);
				backToMenu.draw(window);
			}
			//window.draw(gameOverSprite);
			gameOverTimer += speedModifier;
			return;
		}
	}

	for (GameObject* obj : gameObjects){
		obj->update(speedModifier);
	}

	for (GameObject* obj : gameObjects){
		obj->move(speedModifier);
	}
	
	spawnEnemies(speedModifier);

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
	return GameController::getInstance().getWindow().mapPixelToCoords(sf::Mouse::getPosition(GameController::getInstance().getWindow()));// - sf::Vector2f(mainView.getSize().x/2.f, mainView.getSize().y/2.f) + mainView.getCenter();
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

void LevelController::reset(){
	curLevel = 0;
	WeaponManager::getInstance().dagger->reset();
	WeaponManager::getInstance().pistol->reset();
	WeaponManager::getInstance().sniper->reset();
	WeaponManager::getInstance().rifle->reset();
	WeaponManager::getInstance().shotgun->reset();
	WeaponManager::getInstance().sword->reset();
	//player->setWeapons(WeaponManager::getInstance().dagger, WeaponManager::getInstance().pistol, WeaponManager::getInstance().shotgun);

}
/*
LevelController::~LevelController()
{
for (GameObject* obj : gameObjects){
obj->~GameObject();
}
}*/
