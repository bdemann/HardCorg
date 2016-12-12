#pragma once
#include "gameObject.h"
class Explosion :
	public GameObject
{
public:
	Explosion(int x, int y, Mesh* mesh, Texture* texture) : GameObject(x,y,mesh,texture){
		timer = 5;
	}

	~Explosion() {

	}

	void decrementTimer() {
		timer--;
	}
	int getTimer() {
		return timer;
	}
private:
	int timer;
};

