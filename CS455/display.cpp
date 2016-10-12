#include "display.h"
#include <iostream>
#include <GL/glew.h>
#include "camera.h"
#include "transform.h"


Display::Display(int width, int height, const std::string& title) {
	SDL_Init(SDL_INIT_EVERYTHING);

	printf("%i joysticks were found.\n\n", SDL_NumJoysticks());
	/*printf("The names of the joysticks are:\n");

	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		printf("    %s\n", SDL_JoystickName(i));
	}*/

	if (SDL_NumJoysticks() > 0) {
		SDL_JoystickEventState(SDL_ENABLE);
		joystick = SDL_JoystickOpen(0);
		printf("The names of the joysticks are: %s", SDL_JoystickName(joystick));
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		std::cerr << "Glew failed to initialize." << std::endl;
	}

	closed = false;

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}


Display::~Display() {
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	if (SDL_NumJoysticks() > 0) {
		SDL_JoystickClose(joystick);
	}
	SDL_Quit();
}

void Display::update(Camera& camera, Transform& trans1, Transform& trans2) {
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		std::string direction;

		switch (e.type) {
		case SDL_QUIT:
			closed = true;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_w:
				direction = "forward";
				camera.translateZ(-0.1f);
				break;
			case SDLK_s:
				direction = "back";
				camera.translateZ(0.1f);
				break;
			case SDLK_a:
				direction = "left";
				camera.translateX(-0.1f);
				break;
			case SDLK_d:
				direction = "right";
				camera.translateX(0.1f);
				break;
			case SDLK_r:
				direction = "up";
				camera.translateY(0.1f);
				break;
			case SDLK_f:
				direction = "down";
				camera.translateY(-0.1f);
				break;
			case SDLK_i:
				direction = "camera up";
				camera.rotateX(0.1f);
				break;
			case SDLK_k:
				direction = "camera down";
				camera.rotateX(-0.1f);
				break;
			case SDLK_l:
				direction = "camera right";
				camera.rotateY(-0.1f);
				break;
			case SDLK_j:
				direction = "camera left";
				camera.rotateY(0.1f);
				break;
			case SDLK_y:
				direction = "camera right";
				camera.rotateZ(-0.1f);
				break;
			case SDLK_h:
				direction = "camera left";
				camera.rotateZ(0.1f);
				break;
			case SDLK_RIGHT:
				setRotation(-0.01f);
				break;
			case SDLK_LEFT:
				setRotation(0.01f);
				break;
			default:
				direction = "null";
				break;
			}
			break;
		case SDL_JOYAXISMOTION:
			if ((e.jaxis.value < -3200) || (e.jaxis.value > 3200)) {
				if (e.jaxis.axis == 0) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Run Right" << std::endl;
							camera.translateX(-0.1f);
						}
						else {
							std::cout << "Walk Right" << std::endl;
							camera.translateX(-0.05f);
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Run Left" << std::endl;
							camera.translateX(0.1f);
						}
						else {
							std::cout << "Walk Left" << std::endl;
							camera.translateX(0.05f);
						}
					}
				}
				if (e.jaxis.axis == 1) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Run Backwards" << std::endl;
							camera.translateZ(-0.1f);
						}
						else {
							std::cout << "Walk Backwards" << std::endl;
							camera.translateZ(-0.05f);
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Run Forward" << std::endl;
							camera.translateZ(0.1f);
						}
						else {
							std::cout << "Walk Forward" << std::endl;
							camera.translateZ(0.05f);
						}
					}
				}
				if (e.jaxis.axis == 2) {
					std::cout << "Left-Trigger" << std::endl;
					camera.translateY(0.1f);
				}
				if (e.jaxis.axis == 3) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Camera Fast to Right" << std::endl;
							camera.rotateY(0.1f);
						}
						else {
							std::cout << "Camera Slow to Right" << std::endl;
							camera.rotateY(0.05f);
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Camera Fast to Left" << std::endl;
							camera.rotateY(-0.1f);
						}
						else {
							std::cout << "Camera Slow to Left" << std::endl;
							camera.rotateY(-0.05f);
						}
					}
				}
				if (e.jaxis.axis == 4) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Camera Fast Down" << std::endl;
							camera.rotateX(-0.1f);
						}
						else {
							std::cout << "Camera Slow Down" << std::endl;
							camera.rotateX(-0.05f);
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Camera Fast Up" << std::endl;
							camera.rotateX(0.1f);
						}
						else {
							std::cout << "Camera Slow Up" << std::endl;
							camera.rotateX(0.05f);
						}
					}
				}
				if (e.jaxis.axis == 5) {
					std::cout << "Right-Trigger" << std::endl;
					camera.translateY(-0.1f);
				}
			}
			break;
		case SDL_JOYBUTTONDOWN:
			switch (e.jbutton.button) {
			case 0:
				//std::cout << "Button A" << std::endl;
				break;
			case 1:
				//std::cout << "Button B" << std::endl;
				break;
			case 2:
				//std::cout << "Button X" << std::endl;
				break;
			case 3:
				//std::cout << "Button Y" << std::endl;
				break;
			case 4:
				//std::cout << "Left Trigger" << std::endl;
				break;
			case 5:
				//std::cout << "Right Trigger" << std::endl;
				break;
			default:
				break;
			}
			break;
		case SDL_JOYHATMOTION:
			if (e.jhat.value & SDL_HAT_UP) {
				std::cout << "Run Forward" << std::endl;
			}
			if (e.jhat.value & SDL_HAT_DOWN) {
				std::cout << "Run Backwards" << std::endl;
			}
			if (e.jhat.value & SDL_HAT_RIGHT) {
				std::cout << "Run Right" << std::endl;
			}
			if (e.jhat.value & SDL_HAT_LEFT) {
				std::cout << "Run Left" << std::endl;
			}
		}
	}
}

void Display::clear(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Display::isClosed() {
	return closed;
}
