#include "wall.h"



Wall::Wall(int x, int y, Mesh* mesh, Texture* texture) : GameObject(x, y, mesh, texture)
{
	this->destructable = false;
	this->impassable = true;
}


Wall::~Wall()
{
}
