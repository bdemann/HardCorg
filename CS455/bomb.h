#pragma once
#include "gameObject.h"
#include <string>

class Bomb : public GameObject
{
public:
	Bomb(int x, int y, int blastRadius);
	~Bomb();

	void decrementTimer();
	int getTimer();
	std::string toString();
	int getBlastRadius();
	void setBlastRadius(int blastRadius);

private:
	int timer;
	int blastRadius;
};

