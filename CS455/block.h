#pragma once
#include "gameObject.h"
#include <string>
#include <time.h>

class Block : public GameObject
{
public:
	Block(int x, int y, Mesh* mesh, Texture* texture);
	~Block();

	std::string toString();
	static Block* create(int row, int col, Mesh* mesh, Texture* texture, int blockDensity) {
		int num = rand();
		if (num % blockDensity == 0) {
			return new Block(row, col, mesh, texture);
		}
		return NULL;
	}

private:
	int hp;
};

