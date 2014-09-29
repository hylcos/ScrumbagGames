#include "Bullet.h"

Bullet::Bullet(std::string imagename,float rotation, short bulletSpeed, int damage, sf::Vector2f position) :
rotation{ rotation },
bulletSpeed{ bulletSpeed },
posOld{ position },
damage{damage}
{
	tex = *TextureManager::getInstance().getTexture(imagename);
	sprite.setTexture(tex);
	std::cout << "pew pew pew pew \n";

	LevelController::getInstance().addObject(this);
	std::cout << "Added to the biggest vector list ever \n";
}


void Bullet::update(float speedmodifer) {
	collision[0] = sf::Vertex(posOld);
	collision[1] = sf::Vertex(posNew);
	if (posNew.x > 1280 || posNew.x < 0 || posNew.y > 960 || posNew.y < 0){
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
