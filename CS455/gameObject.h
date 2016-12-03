#pragma once
#include <string>
#include "mesh.h"
#include "texture.h"

class GameObject
{
public:
	GameObject(int x, int y, Mesh* mesh, Texture* texture);
	~GameObject();

	std::string toString();

	int GameObject::getRow() {
		return row;
	}
	int GameObject::getCol() {
		return col;
	}
	Mesh* getMesh() {
		return mesh;
	}
	Texture* getTexture() {
		return texture;
	}
	float getRotation() {
		return 0;
	}

	bool isImpassable() {
		return impassable;
	}
	bool isDestructable() {
		return destructable;
	}

protected:
	int row;
	int col;
	Mesh* mesh;
	Texture* texture;
	bool destructable;
	bool impassable;
};

