#include "floor.h"



Floor::Floor(int x, int y) : GameObject(x, y)
{
}


Floor::~Floor()
{
}

std::string Floor::toString()
{
	return "_";
}