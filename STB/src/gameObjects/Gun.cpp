
#include "Gun.h"
#include "../LevelController.h"
Gun::Gun(std::string name, int damage, float reloadSpeed, int magazineSize, int range, short bulletSpeed) :
damage{ damage },
reloadSpeed{ reloadSpeed },
magazineSize{ magazineSize },
range{ range },
bulletSpeed{ bulletSpeed }
{
	Gun::name = name;
	tex = *TextureManager::getInstance().getTexture(name + ".png");
	TextureManager::getInstance().getTexture(name + "_bullet.png");
	sprite.setTexture(tex);
	sprite.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);
}

void Gun::fire(){
	Bullet * newBullet = new Bullet(name + "_bullet.png", rotation, bulletSpeed, damage, position);
	LevelController::getInstance().addObject(newBullet);
}
void Gun::setRotation(float rotation){
	this->rotation = rotation;
}
void Gun::update(float speedModifier) {

	sprite.setPosition(position);
	sprite.setRotation(rotation);
}
void Gun::draw(sf::RenderWindow & window) const {
	window.draw(sprite);
}

Gun::~Gun()
{
}
