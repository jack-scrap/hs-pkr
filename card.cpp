#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "card.h"
#include "math.h"

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

Card::Card(bool t, glm::vec2 loc) :
	_mesh((GLfloat*) _vtc, (GLushort*) _idc, 2 * 3),
	_prog("main", "solid") {
		/* Program */
		_prog.use();

		// Attribute
		GLint attr[1];

		attr[POS] = glGetAttribLocation(_prog._id, "pos");
		glVertexAttribPointer(attr[POS], 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(attr[POS]);

		// Uniform
		GLint uni[3];

		uni[LOC] = glGetUniformLocation(_prog._id, "loc");
		glUniform2fv(uni[LOC], 1, glm::value_ptr(loc));

		uni[T] = glGetUniformLocation(_prog._id, "t");
		glUniform1ui(uni[T], t);

		uni[RES] = glGetUniformLocation(_prog._id, "res");
		glUniform2ui(uni[RES], res[X], res[Y]);

		_prog.unUse();
	}

void Card::draw() {
	glBindVertexArray(_mesh._vao);
	_prog.use();

	glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_SHORT, (GLvoid*) 0);

	_prog.unUse();
	glBindVertexArray(0);
}
