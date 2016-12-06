#pragma once
#include "gameObject.h"
#include "mesh.h"
#include "texture.h"
#include <string>

enum class Direction {UP, DOWN, LEFT, RIGHT};

class Corgi : public GameObject
{
public:
	Corgi(int x, int y, Mesh* mesh, Texture* texture, Mesh* ghostMesh, Texture* ghostTexture);
	~Corgi();

	std::string toString();
	void move(Direction dir);
	void turn(Direction dir);
	void setInfinite(bool infinite);
	int getBlastRadius();
	void setBlastRadius(int blastRadius);
	float getRotation();
	virtual Mesh* getMesh() {
		if (isDestroyed()) {
			return ghostMesh;
		}
		return mesh;
	}
	virtual Texture* getTexture() {
		if (isDestroyed()) {
			return ghostTexture;
		}
		return texture;
	}
private:
	Direction dir;
	int hp;
	int blastRadius;
	bool infinite;
	Mesh* ghostMesh;
	Texture* ghostTexture;
};

