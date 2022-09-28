#pragma once

#include <GL/glew.h>

class Mesh {
	public:
		GLuint _vao;

		Mesh(GLfloat* vtc, GLushort* idc, unsigned int noEl);
};
