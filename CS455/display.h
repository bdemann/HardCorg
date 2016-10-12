#pragma once

#include <SDL2\SDL.h>
#undef main
#include <string>
#include "camera.h"
#include "transform.h"

class Display{
public:
	Display(int width, int height, const std::string& title);

	void clear(float r, float g, float b, float a);
	void update(Camera& camera, Transform& trans1, Transform& trans2);
	bool isClosed();

	inline void setRotation(float amt) {
		rotation += amt;
		float maxRot = 3.141596 / 4;
		if (rotation > maxRot) {
			rotation = maxRot;
		} else if (rotation < -maxRot) {
			rotation = -maxRot;
		}
	}

	inline float getRotation() { return rotation; }

	virtual ~Display();
private:
	Display(const Display& other) {}
	void operator = (const Display& other) {}

	float rotation = 0;

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	SDL_Joystick *joystick;
	bool closed;
};

