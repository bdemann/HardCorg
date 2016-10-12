#include "transform.h"
#include <string>
#include "glm\glm.hpp"
#include "glm/gtx/transform.hpp"
#include <iostream>

std::string matrixToString(glm::mat4  m);

Transform::~Transform()
{
}

glm::mat4 Transform::getTransMatrix() const {
	glm::mat4 translate = glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, position.x, position.y, position.z, 1);
	glm::mat4 scale = glm::mat4(this->scale.x, 0, 0, 0, 0, this->scale.y, 0, 0, 0, 0, this->scale.z, 0, 0, 0, 0, 1);

	glm::mat4 rotateX = glm::mat4(1, 0, 0, 0, 0, cos(rotation.x), sin(rotation.x), 0, 0, -sin(rotation.x), cos(rotation.x), 0, 0, 0, 0, 1);
	glm::mat4 rotateY = glm::mat4(cos(rotation.y), 0, -sin(rotation.y), 0, 0, 1, 0, 0, sin(rotation.y), 0, cos(rotation.y), 0, 0, 0, 0, 1);
	glm::mat4 rotateZ = glm::mat4(cos(rotation.z), sin(rotation.z), 0, 0, -sin(rotation.z), cos(rotation.z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

	glm::mat4 rotate = rotateZ * rotateY * rotateX;
	return translate * rotate * scale;
}

glm::mat4 Transform::getTransMatrixInverse() const {
	glm::mat4 translate = glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -position.x, -position.y, -position.z, 1);
	glm::mat4 scale = glm::inverse(glm::mat4(this->scale.x, 0, 0, 0, 0, this->scale.y, 0, 0, 0, 0, this->scale.z, 0, 0, 0, 0, 1));

	glm::mat4 rotateX = glm::mat4(1, 0, 0, 0, 0, cos(-rotation.x), sin(-rotation.x), 0, 0, -sin(-rotation.x), cos(-rotation.x), 0, 0, 0, 0, 1);
	glm::mat4 rotateY = glm::mat4(cos(-rotation.y), 0, -sin(-rotation.y), 0, 0, 1, 0, 0, sin(-rotation.y), 0, cos(-rotation.y), 0, 0, 0, 0, 1);
	glm::mat4 rotateZ = glm::mat4(cos(-rotation.z), sin(-rotation.z), 0, 0, -sin(-rotation.z), cos(-rotation.z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

	glm::mat4 rotate = rotateX * rotateY * rotateZ;
	return scale * rotate * translate;
}

std::string matrixToString(glm::mat4  m) {
	m[0][0] = 2;
	std::string x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3;
	x0 = std::to_string(m[0][0]);
	y0 = std::to_string(m[1][0]);
	z0 = std::to_string(m[2][0]);
	w0 = std::to_string(m[3][0]);
	x1 = std::to_string(m[0][1]);
	y1 = std::to_string(m[1][1]);
	z1 = std::to_string(m[2][1]);
	w1 = std::to_string(m[3][1]);
	x2 = std::to_string(m[0][2]);
	y2 = std::to_string(m[1][2]);
	z2 = std::to_string(m[2][2]);
	w2 = std::to_string(m[3][2]);
	x3 = std::to_string(m[0][3]);
	y3 = std::to_string(m[1][3]);
	z3 = std::to_string(m[2][3]);
	w3 = std::to_string(m[3][3]);
	return "[" + x0 + "," + y0 + "," + z0 + "," + w0 + "]\n[" + x1 + "," + y1 + "," + z1 + "," + w1 + "]\n[" + x2 + "," + y2 + "," + z2 + "," + w2 + "]\n[" + x3 + "," + y3 + "," + z3 + "," + w3 + "]";
}

