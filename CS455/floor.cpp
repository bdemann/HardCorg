#include "floor.h"



Floor::Floor(int x, int y, Mesh* mesh, Texture* texture) : GameObject(x, y, mesh, texture)
{
	this->destructable = false;
}


Floor::~Floor()
{
}

std::string Floor::toString()
{
	return "_";
}