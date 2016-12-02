#pragma once
#include <string>

class GameObject
{
public:
	GameObject(int x, int y);
	~GameObject();

	std::string toString();
	int getX();
	int getY();

protected:
	int x;
	int y;
	bool destructable;
};

