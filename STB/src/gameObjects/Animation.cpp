#include "../stdafx.h"
#include "Animation.h"

Animation::Animation(){

}
void Animation::setTextures(sf::Texture & tex1, sf::Texture & tex2, sf::Texture & tex3, sf::Texture & tex4,
	sf::Texture & tex5, sf::Texture & tex6, sf::Texture & tex7, sf::Texture & tex8){
	tex[0] = tex1;
	tex[1] = tex2;
	tex[2] = tex3;
	tex[3] = tex4;
	tex[4] = tex5;
	tex[5] = tex6;
	tex[6] = tex7;
	tex[7] = tex8;
	current = 0;
	curSprite.setTexture(tex[current]);
	curSprite.setOrigin(tex1.getSize().x / 2.0f, tex1.getSize().y / 2.0f);
	
}
void Animation::next(){
	current++;
	if (tex[current].getSize().x == 0 || current == 8)
		current = 0;
	curSprite.setTexture(tex[current]);
}
void Animation::update(float speedModifier) {
	if (toNext >= 10){
		Animation::next();
		toNext -= 10;
	}
	curSprite = *Animation::getCurrentAnimation();
	curSprite.setPosition(position);
	curSprite.setRotation(rotation);
}

void Animation::move(float speedModifier){

}

void Animation::setRotation(float rotation){
	Animation::rotation = rotation;
}

void Animation::draw(sf::RenderWindow & window) const {
	window.draw(curSprite);
}
sf::Sprite * Animation::getCurrentAnimation() {
	return &curSprite;
}
Animation::~Animation()
{
}

