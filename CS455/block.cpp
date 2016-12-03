#include "block.h"

Block::Block(int x, int y, Mesh* mesh, Texture* texture) : GameObject(x, y, mesh, texture)
{
	this->destructable = true;
	this->hp = 1;
}

Block::~Block()
{
}

std::string Block::toString()
{
	return "B";
}