#include "corgi.h"



Corgi::Corgi(int x, int y, Mesh* mesh, Texture* texture) : GameObject(x, y, mesh, texture)
{
	this->destructable = true;
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
		row--;
		break;
	case Direction::DOWN:
		row++;
		break;
	case Direction::LEFT:
		col--;
		break;
	case Direction::RIGHT:
		col++;
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

float Corgi::getRotation() {
	switch (dir)
	{
	case Direction::UP:
		return 3.14159 * 0;
	case Direction::DOWN:
		return 3.14159 / 2;
	case Direction::LEFT:
		return 3.14159 * 3 / 2;
	case Direction::RIGHT:
		return 3.14159 * 1;
	}
}