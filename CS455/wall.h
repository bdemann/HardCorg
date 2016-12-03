#pragma once
#include "gameObject.h"
class Wall : public GameObject
{
public:
	Wall(int x, int y, Mesh* mesh, Texture* texture);
	~Wall();
};

