#pragma once
#include "GameObject.h"
static sf::Texture * NUL = new sf::Texture{};
class Animation : public GameObject
{
public:
	Animation();
	void setTextures(sf::Texture & tex1, sf::Texture & tex2 =* NUL, sf::Texture & tex3 =* NUL, sf::Texture & tex4 = *NUL,
		sf::Texture & tex5 = *NUL, sf::Texture & tex6 =* NUL, sf::Texture & tex7 = *NUL, sf::Texture & tex8 =* NUL);
	void Animation::next() override;
	void Animation::update(float speedModifier) override;
	void Animation::draw(sf::RenderWindow & window) const override;
	void Animation::move(float speedModifier) override;
	void Animation::setRotation(float rotation) override;
	sf::Sprite *  Animation::getCurrentAnimation()  ;
	~Animation();
private:
	sf::Texture  tex[8];
	sf::Sprite curSprite;
	int count = 0;
	int current = 0;
	float rotation = 0.0;
protected:

	float toNext = 0.0;
};

