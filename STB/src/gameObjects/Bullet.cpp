#include "Bullet.h"
#include "../LevelController.h"

Bullet::Bullet(std::string imagename, float rotation, short bulletSpeed, int damage, sf::Vector2f position) :

rotation{ rotation },
bulletSpeed{ bulletSpeed },
damage{ damage }
{
	GameObject::position.x = position.x ;
	GameObject::position.y = position.y;
	tex = *TextureManager::getInstance().getTexture(imagename);
	sprite.setTexture(tex);
}


void Bullet::update(float speedmodifer) {
	position.x += cos((rotation-90)*PI / 180);
	position.y += sin((rotation-90)*PI / 180);
	sprite.setPosition(position);
	if (position.x > 1280 || position.x < 0 || position.y > 960 || position.y < 0){

		LevelController::getInstance().removeObject(this);
		Bullet::~Bullet();
	}

}
void Bullet::draw(sf::RenderWindow & window) const {
	sf::RectangleShape rect{};
	rect.setPosition(sf::Vector2f{ position.x, position.y });
	rect.setSize(sf::Vector2f{ 1, -100 });
	rect.setRotation(rotation);
	window.draw(rect);
	window.draw(sprite);
}
sf::FloatRect Bullet::getLine(){
	return collision.getBounds();
}
Bullet::~Bullet()
{
}
