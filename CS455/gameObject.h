#pragma once
#include <string>
#include "mesh.h"
#include "texture.h"

class GameObject
{
public:
	GameObject(int x, int y, Mesh* mesh, Texture* texture);
	~GameObject();

	virtual std::string toString();

	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
	virtual Mesh* getMesh() {
		return mesh;
	}
	virtual Texture* getTexture() {
		return texture;
	}
	float getRotation() {
		return 0;
	}

	bool isImpassable() {
		return impassable && !isDestroyed();
	}
	bool isDestructable() {
		return destructable;
	}
	virtual void hit() {
		if (destructable) {
			hp--;
		} else {
			hp = 1;
		}
	}
	virtual bool isDestroyed() {
		return hp < 1 && isDestructable();
	}

protected:
	int row;
	int col;
	Mesh* mesh;
	Texture* texture;
	bool destructable;
	bool impassable;
	int hp;
};

