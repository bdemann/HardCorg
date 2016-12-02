#include "camera.h"
#include <glm\glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

Camera::Camera(glm::vec3& position, glm::vec3& lookAt, glm::vec3& up, int width, int height) {
	this->position = position;
	this->lookAt = lookAt;
	this->up = up;

	this->n = glm::normalize(position - lookAt); //Switch these if you find that you are coming in backwards
	this->u = glm::normalize(glm::cross(up, n));
	this->v = glm::normalize(glm::cross(n, u));
	
	this->rotate = glm::mat4(u.x, v.x, n.x, 0, u.y, v.y, n.y, 0, u.z, v.z, n.z, 0, 0, 0, 0, 1);
	this->scale = glm::mat4(1.0);

	this->fov = (float)M_PI/3;
	this->aspect = (float)width/(float)height;
	this->zNear = 0.001f;
	this->zFar = 1000.0f;

	this->perspective = clip();
	this->perspective = glm::perspective(fov, 1.0f, zNear, zFar);
}

glm::mat4 Camera::getViewProjection() const {
	//return perspective * glm::lookAt(position, position - lookAt, up);
	return perspective * worldToCamera();
}

glm::mat4 Camera::rotateCamera() const {
	return rotate;
}

glm::mat4 Camera::translateCamera() const {
	float x = -position.x;
	float y = -position.y;
	float z = -position.z;

	return glm::mat4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, z, 1);
}

glm::mat4 Camera::worldToCamera() const {
	return scale * rotateCamera() * translateCamera();
}

glm::mat4 Camera::clip() const {
	float zoom = 1/tan(fov/2);		//Also what on earth are the next three lines of code?? 
	float x0 = zoom * (1 / aspect); //They don't seem to make sence... 
	float y1 = zoom;				//They aren't like anything else online or in Prof Egbert's Slides
	//float fovX = M_PI * 3;		//BTW these are from my own CS 355 lab. I'm just confused at why it is different.
	//float fovY = M_PI * 3;

	//float x0 = atan2(fovX,2);
	//float y1 = atan2(fovY,2);
	float z2 = -(zFar + zNear) / (zFar - zNear);
	float z3 = (-2 * zNear * zFar) / (zFar - zNear);
	float w2 = -1;
	return glm::mat4(x0, 0, 0, 0, 0, y1, 0, 0, 0, 0, z2, w2, 0, 0, z3, 0);
}

glm::vec3 Camera::getXVector() const {
	return rotateCamera() * glm::vec4(1, 0, 0, 1);
}

glm::vec3 Camera::getYVector() const {
	return rotateCamera() * glm::vec4(0, 1, 0, 1);
}

glm::vec3 Camera::getZVector() const {
	return rotateCamera() * glm::vec4(0, 0, 1, 1);
}

void Camera::translateZ(float amt) {
	position += getZVector() * amt;
}
void Camera::translateX(float amt) {
	position += getXVector() * amt;
}
void Camera::translateY(float amt) {
	position += getYVector() * amt;
}
void Camera::rotateX(float x) {
	glm::mat4 rotateX(1, 0, 0, 0, 0, cos(x), sin(x), 0, 0, -sin(x), cos(x), 0, 0, 0, 0, 1);
	rotate = rotate * rotateX;
}
void Camera::rotateY(float y) {
	glm::mat4 rotateY(cos(y), 0, -sin(y), 0, 0, 1, 0, 0, sin(y), 0, cos(y), 0, 0, 0, 0, 1);
	rotate = rotate * rotateY;
}
void Camera::rotateZ(float z) {
	glm::mat4 rotateZ(cos(z), sin(z), 0, 0, -sin(z), cos(z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	rotate = rotate * rotateZ;
}

Camera::~Camera()
{
}
