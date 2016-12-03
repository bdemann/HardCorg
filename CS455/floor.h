#pragma once
#include "gameObject.h"
#include <string>

class Floor : public GameObject
{
public:
	Floor(int x, int y, Mesh* mesh, Texture* texture);
	~Floor();

	std::string toString();
};

