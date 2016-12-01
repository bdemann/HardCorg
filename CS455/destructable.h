#pragma once
class Destructable
{
public:
	virtual void hit() = 0;
	virtual bool isDestroyed() = 0;
};

