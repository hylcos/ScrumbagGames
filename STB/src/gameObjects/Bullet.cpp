#include "Bullet.h"
#include "../LevelController.h"

Bullet::Bullet(std::string imagename, float rotation, short bulletSpeed, int damage, sf::Vector2f position) :

rotation{ rotation },
bulletSpeed{ bulletSpeed },
damage{ damage }
{
	GameObject::position.x = position.x + 16;
	GameObject::position.y = position.y - 12;
	tex = *TextureManager::getInstance().getTexture(imagename);
	sprite.setTexture(tex);



	velocity.y = sin(-(rotation * 180 / 3.14159265358979323846f - 90)) * bulletSpeed;
	velocity.x = cos((rotation * 180 / 3.14159265358979323846f - 90)) * bulletSpeed;


}


void Bullet::update(float speedmodifer) {
	position += velocity * speedmodifer;
	sprite.setPosition(position);
	if (position.x > 1280 || position.x < 0 || position.y > 960 || position.y < 0){

		LevelController::getInstance().removeObject(this);
		Bullet::~Bullet();
	}

}
void Bullet::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}
sf::FloatRect Bullet::getLine(){
	return collision.getBounds();
}
Bullet::~Bullet()
{
}
