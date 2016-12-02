#pragma once
#include "gameObject.h"
#include <string>

class Block : public GameObject
{
public:
	Block(int x, int y);
	~Block();

	void hit();
	bool isDestroyed();
	std::string toString();

private:
	int hp;
};

