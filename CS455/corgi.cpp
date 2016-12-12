#include "corgi.h"



Corgi::Corgi(int x, int y, Mesh* mesh, Texture* texture, Mesh* ghostMesh, Texture* ghostTexture) : GameObject(x, y, mesh, texture)
{
	this->destructable = true;
	this->dir = Direction::UP;
	this->hp = 1;
	this->numBombs = 1;
	this->blastRadius = 5;
	this->infinite = false;
	this->ghostMesh = ghostMesh;
	this->ghostTexture = ghostTexture;
}


Corgi::~Corgi()
{
}

std::string Corgi::toString()
{
	switch (dir)
	{
	case Direction::UP:
		return "U";
	case Direction::DOWN:
		return "D";
	case Direction::LEFT:
		return "L";;
	case Direction::RIGHT:
		return "R";
	}
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

void Corgi::turn(Direction dir) {
	this->dir = dir;
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
		return (float)(3.14159 * 1);
	case Direction::DOWN:
		return (float)(3.14159 * 0);
	case Direction::LEFT:
		return (float)(3.14159 * 3 / 2);
	case Direction::RIGHT:
		return (float)(3.14159 / 2);
	}
}