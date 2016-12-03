#pragma once
#include "gameObject.h"
#include <string>

class Bomb : public GameObject
{
public:
	Bomb(int x, int y, Mesh* mesh, Texture* texture, int blastRadius);
	~Bomb();

	void hit() {
		timer = 0;
	}

	bool isDestroyed() {
		return timer <= 0;
	}

	void decrementTimer();
	int getTimer();
	std::string toString();
	int getBlastRadius();
	void setBlastRadius(int blastRadius);

private:
	int timer;
	int blastRadius;
};

