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

}
void Animation::next(){
	current++;
	if ( & tex[current]  ==  & NUL )
		current = 0;
	curSprite.setTexture(tex[current]);
}
void Animation::update(float speedModifier) {
	curSprite.setPosition(position);
}
void Animation::draw(sf::RenderWindow & window) const {}
sf::Sprite Animation::getCurrentAnimation() const{
	return curSprite;
}
Animation::~Animation()
{
}

