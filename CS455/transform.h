#pragma once

#include <glm/glm.hpp>j
#include <string>

class Transform
{
public:
	Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale) : position(const_cast<glm::vec3&>(position)), rotation(const_cast<glm::vec3&>(rotation)), scale(const_cast<glm::vec3&>(scale)) {};
	Transform(const glm::vec3& position = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const float scale = 1.0) : Transform(position, rotation, glm::vec3(scale, scale, scale)) {};
	virtual ~Transform();

	glm::mat4 getTransMatrix() const; 
	glm::mat4 getTransMatrixInverse() const;

	inline glm::vec3& getPosition() { return position; }
	inline glm::vec3& getRotation() { return rotation; }
	inline glm::vec3& getScale() { return scale; }

	/*inline void setPosition(glm::vec3& position) { this->position = position; }
	inline void setRotation(glm::vec3& rotation) { this->rotation = rotation; }
	inline void setScale(glm::vec3& scale) { this->scale = scale; }
	inline void setPosition(float x, float y, float z) { position = glm::vec3(x, y, z); }
	inline void setRotation(float x, float y, float z) { rotation = glm::vec3(x, y, z); }
	inline void setScale(float x, float y, float z) { scale = glm::vec3(x, y, z); }

	void rotate(float amt) {
		rotation.y += amt;
	}*/
	std::string toString() {
		std::string x = std::to_string(position.x);
		std::string z = std::to_string(position.z);
		return x + " and " + z;
	}

	void operator = (const Transform& other) {
		position = other.position;
		rotation = other.rotation;
		scale = other.scale;
	}
private:
	//Transform(const Transform& other) {}

	glm::vec3& position;
	glm::vec3& rotation;
	glm::vec3& scale;
};

