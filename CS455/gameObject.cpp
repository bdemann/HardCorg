#include "gameObject.h"
#include "mesh.h"

GameObject::GameObject(int x, int y)
{
}

GameObject::~GameObject()
{
}

std::string GameObject::toString()
{
	return "%";
}

int GameObject::getX()
{
	return x;
}

int GameObject::getY()
{
	return y;
}