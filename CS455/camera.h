#pragma once

#include <glm/glm.hpp>
#include "transform.h"

class Camera
{
public:
	Camera(glm::vec3& position, glm::vec3& lookAt, glm::vec3& up, int width, int height);
	virtual ~Camera();
	glm::mat4 getViewProjection() const;

	glm::mat4 rotateCamera(int direction = 1) const;

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

