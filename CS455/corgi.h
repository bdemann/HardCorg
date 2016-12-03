#pragma once
#include "gameObject.h"
#include <string>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Corgi : public GameObject
{
public:
	Corgi(int x, int y, Mesh* mesh, Texture* texture);
	~Corgi();

	std::string toString();
	void move(Direction dir);
	void turn(Direction dir);
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

