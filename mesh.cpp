#include "mesh.h"

Mesh::Mesh(GLfloat* vtc, GLushort* idc, unsigned int noEl) {
	/* Data */
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// Position
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, noEl * 2 * sizeof (GLfloat), vtc, GL_STATIC_DRAW);

	// Index
	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noEl * sizeof (GLushort), idc, GL_STATIC_DRAW);
}
