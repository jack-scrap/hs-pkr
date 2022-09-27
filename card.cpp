#include "card.h"

Card::Card() :
	_prog("main", "solid") {
		/* Data */
		glGenVertexArrays(1, &_vao);
		glBindVertexArray(_vao);

		// Position
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		const GLfloat vtc[2 * 2 * 2] = {
			-1.0, -2.0,
			1.0, -2.0,
			-1.0, 2.0,
			1.0, 2.0
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof vtc, vtc, GL_STATIC_DRAW);

		GLuint ibo;
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		const GLushort idc[] = {
			0, 1, 2,
			2, 1, 3
		};

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof idc, idc, GL_STATIC_DRAW);

		_prog.use();

		// Attribute
		GLint attrPos = glGetAttribLocation(_prog._id, "pos");
		glVertexAttribPointer(attrPos, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(attrPos);

		_prog.unUse();
	}

void Card::draw() {
	glBindVertexArray(_vao);
	_prog.use();

	glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_SHORT, (GLvoid*) 0);

	_prog.unUse();
	glBindVertexArray(0);
}
