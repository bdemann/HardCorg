#include "corgi.h"



Corgi::Corgi(int x, int y) : GameObject(x, y)
{
	this->dir = Direction::UP;
	this->hp = 1;
	this->blastRadius = 1;
	this->infinite = false;
}


Corgi::~Corgi()
{
}

Direction Corgi::toString()
{
	return dir;
}

void Corgi::move(Direction dir)
{
	switch (dir)
	{
	case Direction::UP:
		x--;
		break;
	case Direction::DOWN:
		x++;
		break;
	case Direction::LEFT:
		y--;
		break;
	case Direction::RIGHT:
		y++;
		break;
	}
	this->dir = dir;
}

void Corgi::hit()
{
	hp--;
}

bool Corgi::isDestroyed()
{
	return hp < 1;
}

void Corgi::setInfinite(bool infinite)
{
	this->infinite = infinite;
}

int Corgi::getBlastRadius()
{
	return blastRadius;
}

void Corgi::setBlastRadius(int blastRadius)
{
	this->blastRadius = blastRadius;
}