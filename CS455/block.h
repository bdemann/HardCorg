#pragma once
#include "destructable.h"
#include "gameObject.h"
#include <string>

class Block : public GameObject, public Destructable
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

