#include "bomb.h"

Bomb::Bomb(int x, int y, Mesh* mesh, Texture* texture, int blastRadius) : GameObject(x, y, mesh, texture)
{
	this->destructable = true;
	this->impassable = true;
	this->timer = 5;
	this->blastRadius = blastRadius;
}

Bomb::~Bomb()
{
}

void Bomb::decrementTimer()
{
	timer--;
}

int Bomb::getTimer()
{
	return timer;
}

std::string Bomb::toString()
{
	if (timer == 0)
		return "X";
	return "O";
}

int Bomb::getBlastRadius()
{
	return blastRadius;
}

void Bomb::setBlastRadius(int blastRadius)
{
	this->blastRadius = blastRadius;
}