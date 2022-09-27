#include "card.h"

extern const unsigned int res[2];

const GLfloat Card::_vtc[2 * 2 * 2] = {
	-1.0, -2.0,
	1.0, -2.0,
	-1.0, 2.0,
	1.0, 2.0
};

const GLushort Card::_idc[2 * 3] = {
	0, 1, 2,
	2, 1, 3
};

Card::Card() :
	_prog("main", "solid") {
		/* Data */
		glGenVertexArrays(1, &_vao);
		glBindVertexArray(_vao);

		// Position
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glBufferData(GL_ARRAY_BUFFER, sizeof _vtc, _vtc, GL_STATIC_DRAW);

		GLuint ibo;
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof _idc, _idc, GL_STATIC_DRAW);

		/* Program */
		_prog.use();

		// Attribute
		GLint attrPos = glGetAttribLocation(_prog._id, "pos");
		glVertexAttribPointer(attrPos, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(attrPos);

		// Uniform
		GLint uniRes = glGetUniformLocation(_prog._id, "res");
		glUniform2ui(uniRes, res[0], res[1]);

		_prog.unUse();
	}

void Card::draw() {
	glBindVertexArray(_vao);
	_prog.use();

	glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_SHORT, (GLvoid*) 0);

	_prog.unUse();
	glBindVertexArray(0);
}
