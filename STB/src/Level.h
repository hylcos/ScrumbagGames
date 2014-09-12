#pragma once
class Level
{
public:
	Level();

	class Initializer{
	public:
		Initializer(char randomness);
	private:
		char randomness;
	};

	void Level::startLevel(Level::Initializer initializer);

	Level::Initializer LEVEL_ONE{ (char)100 };

	~Level();
};

