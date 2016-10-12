#pragma once

#include <GL\glew.h>
#include <string>

class Texture
{
public:
	Texture(const std::string& fileName);

	void bind(unsigned int unit);

	virtual ~Texture();
private:
	Texture(const Texture& other) {}
	void operator=(const Texture& other) {}

	GLuint m_texture = 0;
};

