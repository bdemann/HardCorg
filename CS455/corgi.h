#pragma once
#include "gameObject.h"
#include "destructable.h"
#include <string>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Corgi : public GameObject, public Destructable
{
public:
	Corgi(int x, int y);
	~Corgi();

	Direction toString();
	void move(Direction dir);
	void hit();
	bool isDestroyed();
	void setInfinite(bool infinite);
	int getBlastRadius();
	void setBlastRadius(int blastRadius);
private:
	Direction dir;
	int hp;
	int blastRadius;
	bool infinite;
};

