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
		GLint attrPos = glGetAttribLocation(_prog._id, "pos");
		glVertexAttribPointer(attrPos, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(attrPos);

		// Uniform
		GLint uniLoc = glGetUniformLocation(_prog._id, "loc");
		glUniform2fv(uniLoc, 1, glm::value_ptr(loc));

		GLint uniRes = glGetUniformLocation(_prog._id, "res");
		glUniform2ui(uniRes, res[X], res[Y]);

		GLint uniT = glGetUniformLocation(_prog._id, "t");
		glUniform1ui(uniT, t);

		_prog.unUse();
	}

void Card::draw() {
	glBindVertexArray(_mesh._vao);
	_prog.use();

	glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_SHORT, (GLvoid*) 0);

	_prog.unUse();
	glBindVertexArray(0);
}
