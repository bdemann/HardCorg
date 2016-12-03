#include "gameObject.h"
#include "mesh.h"
#include "texture.h"

GameObject::GameObject(int x, int y, Mesh* mesh, Texture* texture)
{
	this->row = x;
	this->col = y;
	this->mesh = mesh;
	this->texture = texture;
}

GameObject::~GameObject()
{
}

std::string GameObject::toString()
{
	return "%";
}