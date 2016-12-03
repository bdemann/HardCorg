#pragma once

#include <SDL2\SDL.h>
#undef main
#include <string>
#include <vector>
#include "camera.h"
#include "transform.h"

#include "gameObject.h"

class Display{
public:
	Display(int width, int height, const std::string& title);

	void clear(float r, float g, float b, float a);
	void update(Camera& camera);
	bool isClosed();

	virtual ~Display();
private:
	Display(const Display& other) {}
	void operator = (const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	SDL_Joystick *joystick;
	bool closed;

};

