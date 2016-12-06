#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "transform.h"

class Camera
{
public:
	Camera(glm::vec3& position, glm::vec3& lookAt, glm::vec3& up, int width, int height);
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
		this->position = pos;
		this->lookAt = glm::vec3(0.0f, -1.0f, -1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->perspective = glm::perspective(fov, aspect, zNear, zFar);
	}

	inline glm::mat4 getViewProjection() const {
		return perspective * glm::lookAt(position, position + lookAt, up);
	}
	virtual ~Camera();
	//glm::mat4 getViewProjection() const;

	glm::mat4 rotateCamera() const;

	glm::mat4 translateCamera() const;

	glm::mat4 worldToCamera() const;

	glm::mat4 clip() const;

	glm::vec3 getXVector() const;

	glm::vec3 getYVector() const;

	glm::vec3 getZVector() const;

	inline const glm::vec3& getPosition()  { return position; }
	inline const glm::vec3& getRotation() { return rotation; }

	//inline void setPosition(glm::vec3& position) { this->transform.setPosition(position); }
	//inline void setUp(glm::vec3& up) {	this->up = up; }
	//inline void setLookAt(glm::vec3& pAt) { this->lookAt = pAt; }

	void translateZ(float amt);
	void translateX(float amt);
	void translateY(float amt);
	void rotateX(float amt);
	void rotateY(float amt);
	void rotateZ(float amt);

private:
	glm::vec3 n;
	glm::vec3 u;
	glm::vec3 v;

	glm::vec3 position;
	glm::vec3 lookAt;
	glm::vec3 up;
	glm::vec3 rotation;

	glm::mat4 translate;
	glm::mat4 rotate;
	glm::mat4 perspective;
	glm::mat4 scale;

	float zNear;
	float zFar;
	float fov;
	float aspect;
	int width;
	int hieght;
};

