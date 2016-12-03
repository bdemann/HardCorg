#pragma once
#include "gameObject.h"
#include <string>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Corgi : public GameObject
{
public:
	Corgi(int x, int y, Mesh* mesh, Texture* texture);
	~Corgi();

	Direction toString();
	void move(Direction dir);
	void hit();
	bool isDestroyed();
	void setInfinite(bool infinite);
	int getBlastRadius();
	void setBlastRadius(int blastRadius);
	float getRotation();
private:
	Direction dir;
	int hp;
	int blastRadius;
	bool infinite;
};

