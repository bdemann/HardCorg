#include <iostream>
#include <GL/glew.h>
#include <string>
#include <vector>

#include "gameObject.h"

#include "display.h"
#include "camera.h"
#include "transform.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "simpleCamera.h"

#define ROWS 13
#define COLS 13


//std::vector<GameObject> gameBoard[ROWS][COLS];
Transform* transforms[ROWS][COLS];
//std::vector<GameObject> nums;
//GameObject obj;

int main() {
	Display display(800, 600, "Project 3");

	Shader shader("./res/shaders/basicShader");

	Mesh t0("./res/obj/tire.obj");
	Mesh t1("./res/obj/tire.obj");
	Mesh t2("./res/obj/tire.obj");
	Mesh t3("./res/obj/tire.obj");

	float scaleTire = 0.35f;
	glm::vec3 scaleVecTire(scaleTire, scaleTire, scaleTire);
	Transform tt0(glm::vec3(0.5, -0.775, 6.2), glm::vec3(0, 0, 0), scaleVecTire);
	Transform tt1(glm::vec3(-0.5, -0.775, 6.2), glm::vec3(0, 3.141596, 0), scaleVecTire);
	Transform tt2(glm::vec3(0.5, -0.775, 4.875), glm::vec3(0, 0, 0), scaleVecTire);
	Transform tt3(glm::vec3(-0.5, -0.775, 4.875), glm::vec3(0, 3.141596, 0), scaleVecTire);

	Mesh tires[] = { t0, t1, t2, t3 };
	Transform transTires[] = { tt0, tt1, tt2, tt3 };
	Texture textTire("./res/textures/tire.bmp");

	//transforms[0][0] = new Transform(glm::vec3(0.5, -0.775, 6.2), glm::vec3(0, 0, 0), scaleVecTire);

	Mesh ground("./res/obj/ParkingLot.obj");
	Texture textGround("./res/textures/ParkingLot.bmp");
	//Transform transGround(glm::vec3(0, -1, 0), glm::vec3(0, 0, 0), glm::vec3(1.0, 1.0, 1.0));
	Transform transGround(glm::vec3(5.2, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(1.0, 1.0, 1.0));

	Camera camera(glm::vec3(0, 30, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), 800, 600);

	while (!display.isClosed()) {
		display.clear(0.0f, 0.0f, 0.0f, 0);

		shader.bind();

		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				//std::vector<GameObject> cell = gameBoard[row][col];
				//for (int i = 0; i < cell.size(); i++) {
				//	//GameObject piece = cell.at(i);
				//	//piece.bindTexture();
				//	//shader.update(transforms[row][col], camera);
				//	//piece.draw();
				//}
			}
		}

		textGround.bind(0);
		shader.update(transGround, camera);
		ground.draw();

		display.update();
	}


	return 0;
}

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

void Display::update() {
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
				break;
			case SDLK_s:
				direction = "back";
				break;
			case SDLK_a:
				direction = "left";
				break;
			case SDLK_d:
				direction = "right";
				break;
			case SDLK_r:
				direction = "up";
				break;
			case SDLK_f:
				direction = "down";
				break;
			case SDLK_i:
				direction = "camera up";
				break;
			case SDLK_k:
				direction = "camera down";
				break;
			case SDLK_l:
				direction = "camera right";
				break;
			case SDLK_j:
				direction = "camera left";
				break;
			case SDLK_y:
				direction = "camera right";
				break;
			case SDLK_h:
				direction = "camera left";
				break;
			case SDLK_RIGHT:
				break;
			case SDLK_LEFT:
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
						}
						else {
							std::cout << "Walk Right" << std::endl;
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Run Left" << std::endl;
						}
						else {
							std::cout << "Walk Left" << std::endl;
						}
					}
				}
				if (e.jaxis.axis == 1) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Run Backwards" << std::endl;
						}
						else {
							std::cout << "Walk Backwards" << std::endl;
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Run Forward" << std::endl;
						}
						else {
							std::cout << "Walk Forward" << std::endl;
						}
					}
				}
				if (e.jaxis.axis == 2) {
					std::cout << "Left-Trigger" << std::endl;
				}
				if (e.jaxis.axis == 3) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Camera Fast to Right" << std::endl;
						}
						else {
							std::cout << "Camera Slow to Right" << std::endl;
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Camera Fast to Left" << std::endl;
						}
						else {
							std::cout << "Camera Slow to Left" << std::endl;
						}
					}
				}
				if (e.jaxis.axis == 4) {
					if (e.jaxis.value > 0) {
						if (e.jaxis.value > 15000) {
							std::cout << "Camera Fast Down" << std::endl;
						}
						else {
							std::cout << "Camera Slow Down" << std::endl;
						}
					}
					else {
						if (e.jaxis.value < -15000) {
							std::cout << "Camera Fast Up" << std::endl;
						}
						else {
							std::cout << "Camera Slow Up" << std::endl;
						}
					}
				}
				if (e.jaxis.axis == 5) {
					std::cout << "Right-Trigger" << std::endl;
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
