#pragma once
#include "gameObject.h"
#include <string>

class Floor : public GameObject
{
public:
	Floor(int x, int y);
	~Floor();

	std::string toString();
};

