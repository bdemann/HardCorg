#include "gameObject.h"
#include "mesh.h"
#include "texture.h"

GameObject::GameObject(int x, int y, Mesh* mesh, Texture* texture)
{
	this->row = x;
	this->col = y;
	this->mesh = mesh;
	this->texture = texture;
	hp = 1;
}

GameObject::~GameObject()
{
}

std::string GameObject::toString()
{
	return "%";
}