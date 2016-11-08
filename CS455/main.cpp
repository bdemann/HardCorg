#include <iostream>
#include <string>
#include <GL\glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include "simpleCamera.h"
#include <vector>

int main() {
	Display display(800, 600, "Project 3");
	
	Shader shader("./res/shaders/basicShader");

	//Object carOBJ("./res/car.obj", "./res/car.bmp", glm::vec3(0, -0.95, 5.5), glm::vec3(0, 3.141596, 0), 1.3f);
	Mesh car("./res/obj/car.obj");
	Texture textCar("./res/textures/car.bmp");
	Transform transCar(glm::vec3(0, -0.95, 5.5), glm::vec3(0, 3.141596, 0), glm::vec3(1.3, 1.3, 1.3));

	Mesh t0("./res/obj/tire.obj");
	Mesh t1("./res/obj/tire.obj");
	Mesh t2("./res/obj/tire.obj");
	Mesh t3("./res/obj/tire.obj");

	//Object tireOBJ("./res/car.obj", "./res/car.bmp", glm::vec3(0, -0.95, 5.5), glm::vec3(0, 3.141596, 0), 1.3f);
	float scaleTire = 0.35f;
	glm::vec3 scaleVecTire(scaleTire, scaleTire, scaleTire);
	Transform tt0(glm::vec3(0.5, -0.775, 6.2), glm::vec3(0, 0, 0), scaleVecTire);
	Transform tt1(glm::vec3(-0.5, -0.775, 6.2), glm::vec3(0, 3.141596, 0), scaleVecTire);
	Transform tt2(glm::vec3(0.5, -0.775, 4.875), glm::vec3(0, 0, 0), scaleVecTire);
	Transform tt3(glm::vec3(-0.5, -0.775, 4.875), glm::vec3(0, 3.141596, 0), scaleVecTire);

	Mesh tires[] = {t0, t1, t2, t3};
	Transform transTires[] = { tt0, tt1, tt2, tt3 };
	Texture textTire("./res/textures/tire.bmp");

	Mesh lot("./res/obj/ParkingLot.obj");
	Texture textLot("./res/textures/ParkingLot.bmp");
	Transform transLot(glm::vec3(5.2, -1, 0), glm::vec3(0, 3.141596 * 0.6666666, 0), glm::vec3(1.0, 1.0, 1.0));

	//Mesh cat("./res/cat.obj");
	//Texture textCat("./res/cat.jpg");
	//float catScale = 0.175f;
	//Transform transCat(glm::vec3(0, -0.1, 5.25), glm::vec3(0, 0, 0), glm::vec3(catScale, catScale, catScale));

	Camera camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0), 800, 600);

	float counter = 0.0f;

	while (!display.isClosed()) {
		display.clear(0.0f, 0.0f, 0.0f, 0);

		shader.bind();
		//textCar.bind(0);
		//shader.update(transCar, camera);
		//car.draw();

		textLot.bind(0);
		shader.update(transLot, camera);
		lot.draw();

		//transTires[0].getRotation().y = display.getRotation();
		//transTires[1].getRotation().y = display.getRotation() + 3.141596;

		//textTire.bind(0);
		//for (int i = 0; i < 4; i++) {
		//	shader.update(transTires[i], camera);
		//	tires[i].draw();
		//}

		//textCat.bind(0);
		//shader.update(transCat, camera);
		//cat.draw();

		display.update(camera, tt0, tt1);
		counter += 0.005f;
	}
	

	return 0;
}