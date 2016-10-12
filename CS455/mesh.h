#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"

class Vertex {
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord) {
		this->pos = pos;
		this->texCoord = texCoord;
	}

	inline glm::vec3 getPos() {
		return pos;
	}

	inline glm::vec2 getTexCoord() {
		return texCoord;
	}
private:
	glm::vec3 pos;
	glm::vec2 texCoord;
};

class Mesh
{
public:
	//Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(std::string fileName);

	void InitMesh(const IndexedModel& model);

	void draw();
	std::string getFileName() {
		return fileName;
	}

	virtual ~Mesh();
private:
	//void operator = (const Mesh& other) {};
	//Mesh(Mesh& other);

	enum {
		POSITION_VB,
		TEXCOORD_VB,

		INDEX_VB,

		NUM_BUFFERS
	};

	std::string& fileName;
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

