#pragma once

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "camera.h"
#include "simpleCamera.h"

class Shader
{
public:
	Shader(const std::string& fileName);

	void bind();
	void update(const Transform& transform, const Camera& camera);
	void update(const Transform& transform, const SimpleCamera& camera);

	virtual ~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	//What is a uniform? The uniforms are the uniform variables that we set in the basicShader files. transform_u represents the transform matrix that we want to pass in
	enum
	{
		TRANSFROM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

