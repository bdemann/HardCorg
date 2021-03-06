#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class SimpleCamera {
public:
	SimpleCamera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
	}

	inline glm::mat4 getViewProjection() const {
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}

	inline glm::vec3& getPosition() { return m_position; };
	inline glm::vec3& getLookAt() { return m_forward; };

private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
};
