#pragma once

#include <glm\glm.hpp>
#include "mesh.h"
#include "transform.h"
#include "texture.h"

class Object
{
public:
	Object(const std::string& meshFileName, const std::string& textureFileName, const glm::vec3& position, const glm::vec3& rotation, float scale);
	//, std::string& textureFileName, glm::vec3& position, glm::vec3& rotation, float scale
	Object(Object* parent, std::string meshFileName, std::string textureFileName, glm::vec3 position, glm::vec3 rotation, float scale);
	~Object();
	glm::mat4 objectToWorldTranform();
private:
	Transform* trans;
	Mesh* mesh;
	Texture* text;
	Object* parent;
};

