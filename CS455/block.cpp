#include "block.h"

Block::Block(int x, int y, Mesh* mesh, Texture* texture) : GameObject(x, y, mesh, texture)
{
	this->destructable = true;
	this->hp = 1;
}

Block::~Block()
{
}

void Block::hit()
{
	hp--;
}

bool Block::isDestroyed() 
{
	return hp < 1;
}

std::string Block::toString()
{
	return "B";
}