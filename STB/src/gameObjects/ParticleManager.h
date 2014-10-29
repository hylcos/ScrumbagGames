#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class ParticleManager :
	public GameObject
{
public:

	static ParticleManager& getInstance()
	{
		static ParticleManager instance;
		return instance;
	}

	~ParticleManager();
private:
	ParticleManager();
};

