#include "floor.h"



Floor::Floor(int x, int y) : GameObject(x, y)
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