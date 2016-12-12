#include "texture.h"
#include "stb_image.h"
#include <cassert>
#include <iostream>

Texture::Texture(const std::string& fileName) {

	int width, height, numComponents;
	unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

	if (imageData == NULL) {
		std::cerr << "Texture loading failed for texture: Meaning it is null meaning this is a problem?" << fileName << std::endl;
	}

	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	if (m_texture == NULL || width == NULL || height == NULL || numComponents == NULL) {
		std::cerr << "texture or something is null" << std::endl;
		if (width == NULL) {
			std::cout << "width";
		}
		if (height == NULL) {
			std::cout << "height";
		}
		if (numComponents == NULL) {
			std::cout << "numComponents";
		}
		if (m_texture == NULL) {
			std::cout << "Texture";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << m_texture << " " << width << " " << height << " " << numComponents << "." << std::endl;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}

Texture::~Texture() {
	glDeleteTextures(1, &m_texture);
}

void Texture::bind(unsigned int unit) {
	assert(unit >= 0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
