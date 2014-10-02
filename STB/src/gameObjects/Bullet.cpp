#include "Bullet.h"
#include "Enemy.h"
#include "../LevelController.h"
#include <iostream>

Bullet::Bullet(std::string imagename, float rotation, short bulletSpeed, int damage, sf::Vector2f position) :

rotation{ rotation },
bulletSpeed{ bulletSpeed },
damage{ damage }
{
	GameObject::position.x = position.x;
	GameObject::position.y = position.y;
	tex = *TextureManager::getInstance().getTexture(imagename);
	sprite.setTexture(tex);
}

void Bullet::update(float speedmodifier){
	for (GameObject* gameObject : LevelController::getInstance().getGameObjects()){
		if (dynamic_cast<Enemy*>(gameObject) != 0){
			if (gameObject->getBounds().intersects(getBounds())){
				(dynamic_cast<Enemy*>(gameObject))->reduceHP(damage);
				LevelController::getInstance().removeObject(this);
			}
		}
	}
}

void Bullet::move(float speedmodifer) {
	prevPosition = position;
	position.x += cos((rotation - 90)*PI / 180) * speedmodifer * bulletSpeed;
	position.y += sin((rotation - 90)*PI / 180) * speedmodifer * bulletSpeed;
	sprite.setPosition(position);
	if (position.x > 1280 || position.x < 0 || position.y > 960 || position.y < 0){

		LevelController::getInstance().removeObject(this);
		Bullet::~Bullet();
	}

}
void Bullet::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}

sf::FloatRect Bullet::getBounds(){
	return sprite.getGlobalBounds();
}
Bullet::~Bullet()
{
}
