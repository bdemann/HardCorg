#include "object.h"



Object::Object(const std::string& meshFileName, const std::string& textureFileName, const glm::vec3& position, const glm::vec3& rotation, float scale)
{
	//, std::string& textureFileName, glm::vec3& position, glm::vec3& rotation, float scale
	this->mesh = new Mesh(meshFileName);
	//this->trans = new Transform(position, rotation, scale);
	//this->text = new Texture(textureFileName);
	//this->parent = NULL;
}

Object::Object(Object* parent, std::string meshFileName, std::string textureFileName, glm::vec3 position, glm::vec3 rotation, float scale)
{
	this->mesh = new Mesh(meshFileName);
	this->trans = new Transform(position, rotation, scale);
	this->text = new Texture(textureFileName);
	this->parent = parent;
}

glm::mat4 Object::objectToWorldTranform() {
	return trans->getTransMatrix();
}

Object::~Object()
{
	delete(mesh);
	delete(trans);
	delete(text);
	if (parent != NULL) {
		delete(parent);
	}
}
