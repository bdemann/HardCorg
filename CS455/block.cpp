#include "block.h"

Block::Block(int x, int y) : GameObject(x, y)
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