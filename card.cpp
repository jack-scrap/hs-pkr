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
	Obj((GLfloat*) _vtc, (GLushort*) _idc, sizeof _idc / sizeof *_idc, "main", "solid") {
		/* Program */
		_prog.use();

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
