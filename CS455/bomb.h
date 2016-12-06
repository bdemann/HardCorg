#pragma once
#include "gameObject.h"
#include <string>

class Bomb : public GameObject
{
public:
	Bomb(int x, int y, Mesh* mesh, Texture* texture, int blastRadius, int owner);
	~Bomb();

	void hit() {
		timer = 0;
	}

	bool isDestroyed() {
		return timer <= 0 && exploded;
	}

	void explode() {
		exploded = true;
	}

	int getOwner() {
		return owner;
	}

	void decrementTimer();
	int getTimer();
	std::string toString();
	int getBlastRadius();
	void setBlastRadius(int blastRadius);

private:
	int owner;
	int timer;
	int blastRadius;
	int exploded;
};

