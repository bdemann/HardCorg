#include <iostream>
#include <GL/glew.h>
#include <string>
#include <vector>

#include "gameObject.h"
#include "floor.h"
#include "wall.h"
#include "block.h"
#include "corgi.h"

#include "display.h"
#include "camera.h"
#include "transform.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "simpleCamera.h"

#define ROWS 11
#define COLS 11
#define UNIT_WIDTH 2
#define UNIT_HEIGHT 2
#define BLOCK_DENSITY 2

std::vector<GameObject*> gameBoard[ROWS][COLS];
Transform transforms[ROWS][COLS];
int nums[ROWS][COLS];
std::vector<Corgi> corgis;

int main() {
	Display display(800, 600, "Project 3");


	Camera camera(glm::vec3(0, 30, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), 800, 600);
	Shader shader("./res/shaders/basicShader");
	Mesh ground("./res/obj/car.obj");
	Mesh block("./res/obj/monkey.obj");
	Texture textGround("./res/textures/ParkingLot.bmp");
	Texture textWall("./res/textures/car.bmp");
	Texture textBlock("./res/textures/crayon.jpg");

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			//Transform transform = Transform(glm::vec3(row, -1, col), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
			//transforms[row][col] = transform;
			//std::string test = transforms[row][col].toString();
			//std::cout << row << " " << col << " " << test << std::endl;
		}
	}
	/*transforms[0][0] = Transform(glm::vec3(0, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[0][1] = Transform(glm::vec3(0, -1, 1), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[0][2] = Transform(glm::vec3(0, -1, 2), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[1][0] = Transform(glm::vec3(1, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[1][1] = Transform(glm::vec3(1, -1, 1), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[1][2] = Transform(glm::vec3(1, -1, 2), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[2][0] = Transform(glm::vec3(2, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[2][1] = Transform(glm::vec3(2, -1, 1), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[2][2] = Transform(glm::vec3(2, -1, 2), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[3][0] = Transform(glm::vec3(3, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[3][1] = Transform(glm::vec3(3, -1, 1), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[3][2] = Transform(glm::vec3(3, -1, 2), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[4][0] = Transform(glm::vec3(4, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[4][1] = Transform(glm::vec3(4, -1, 1), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));
	transforms[4][2] = Transform(glm::vec3(4, -1, 2), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(.5, .5, .5));*/

	Transform t00 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t01 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t02 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t03 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t04 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t05 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t06 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t07 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t08 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t09 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t0a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t10 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t11 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t12 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t13 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t14 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t15 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t16 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t17 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t18 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t19 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t1a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t20 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t21 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t22 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t23 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t24 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t25 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t26 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t27 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t28 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t29 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t2a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t30 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t31 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t32 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t33 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t34 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t35 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t36 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t37 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t38 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t39 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t3a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t40 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t41 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t42 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t43 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t44 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t45 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t46 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t47 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t48 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t49 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t4a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t50 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t51 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t52 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t53 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t54 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t55 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t56 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t57 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t58 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t59 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t5a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t60 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t61 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t62 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t63 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t64 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t65 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t66 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t67 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t68 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t69 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t6a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t70 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t71 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t72 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t73 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t74 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t75 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t76 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t77 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t78 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t79 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t7a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t80 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t81 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t82 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t83 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t84 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t85 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t86 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t87 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t88 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t89 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t8a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform t90 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t91 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t92 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t93 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t94 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t95 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t96 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t97 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t98 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t99 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform t9a = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform ta0 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta1 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta2 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta3 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta4 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta5 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta6 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta7 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta8 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform ta9 = Transform(glm::vec3(), glm::vec3(), glm::vec3());
	Transform taa = Transform(glm::vec3(), glm::vec3(), glm::vec3());

	Transform transforms[ROWS][COLS] = { { t00,t01,t02,t03,t04,t05,t06,t07,t08,t09,t0a},{ t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t1a},{ t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t2a },{ t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t3a },{ t40,t41,t42,t43,t44,t45,t46,t47,t48,t49,t4a },{ t50,t51,t52,t53,t54,t55,t56,t57,t58,t59,t5a },{ t60,t61,t62,t63,t64,t65,t66,t67,t68,t69,t6a },{ t70,t71,t72,t73,t74,t75,t76,t77,t78,t79,t7a },{ t80,t81,t82,t83,t84,t85,t86,t87,t88,t89,t8a },{ t90,t91,t92,t93,t94,t95,t96,t97,t98,t99,t9a },{ ta0,ta1,ta2,ta3,ta4,ta5,ta6,ta7,ta8,ta9,taa } };

	corgis.push_back(Corgi(1, 1, &block, &textWall));

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			transforms[row][col].getPosition().x = (float)row * UNIT_WIDTH;
			transforms[row][col].getPosition().z = (float)col * UNIT_HEIGHT;

			transforms[row][col].getScale().x = 1;
			transforms[row][col].getScale().y = 1;
			transforms[row][col].getScale().z = 1;

			//Add Walls and floor
			GameObject* piece = new Floor(row, col, &ground, &textGround);
			if ((row % 2 == 0 && col % 2 == 0) || (row == 0 || row == ROWS - 1) || (col == 0 || col == COLS - 1)) {
				piece = new Wall(row, col, &ground, &textWall);
			}

			gameBoard[row][col].push_back(piece);

			//Add Blocks
			//Don't put a block on top of the walls
			if ((row % 2 == 0 && col % 2 == 0) || (row == 0 || row == ROWS - 1) || (col == 0 || col == COLS - 1)) {
				continue;
			}
			//Keep a small pad around the players free from blocks so they aren't trapped from the beginnging.
			if ((row == 1 && col == 1) || (row == 2 && col == 1) || (row == 1 && col == 2)) {
				continue;
			}
			if ((row == 1 && col == COLS - 2) || (row == 2 && col == COLS - 2) || (row == 1 && col == COLS - 3)) {
				continue;
			}
			if ((row == ROWS - 2 && col == 1) || (row == ROWS - 3 && col == 1) || (row == ROWS - 2 && col == 2)) {
				continue;
			}
			if ((row == ROWS - 2 && col == COLS - 2) || (row == ROWS - 3 && col == COLS - 2) || (row == ROWS - 2 && col == COLS - 3)) {
				continue;
			}

			//It after all that checking we must be on a valid block so we can randomly put down a block.
			Block* b = Block::create(row, col, &block, &textBlock, BLOCK_DENSITY);
			if (b != NULL) {
				gameBoard[row][col].push_back(b);
				printf("We added one");
			}
			else {
				printf("We didn't add one");
			}
		}
	}

	while (!display.isClosed()) {
		display.clear(0.0f, 0.0f, 0.0f, 0);

		shader.bind();

		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				std::vector<GameObject*> cell = gameBoard[row][col];
				for (unsigned int i = 0; i < cell.size(); i++) {
					GameObject* piece = cell.at(i);
					piece->getTexture()->bind(0);
					Transform trans = transforms[row][col];
					trans.getRotation().y = piece->getRotation();
					shader.update(trans, camera);
					piece->getMesh()->draw();
				}
			}
		}
		for (Corgi c : corgis) {
			c.getTexture()->bind(0);
			Transform trans = transforms[c.getRow()][c.getCol()];
			trans.getRotation().y = c.getRotation();
			shader.update(trans, camera);
			c.getMesh()->draw();
		}

		display.update(camera);
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

void Display::update(Camera& camera) {
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
				camera.translateZ(1);
				break;
			case SDLK_s:
				direction = "back";
				camera.translateZ(-1);
				break;
			case SDLK_a:
				direction = "left";
				camera.translateX(-1);
				break;
			case SDLK_d:
				direction = "right";
				camera.translateX(1);
				break;
			case SDLK_r:
				direction = "up";
				camera.translateY(-1);
				break;
			case SDLK_f:
				direction = "down";
				camera.translateY(1);
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
				corgis.at(0).move(Direction::RIGHT);
				printf("%f", corgis.at(0).getRotation());
				break;
			case SDLK_LEFT:
				corgis.at(0).move(Direction::LEFT);
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
