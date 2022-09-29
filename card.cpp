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

const GLfloat Card::_diamVtc[] = {
	-1.0, 0.0,
	1.0, 0.0,
	0.0, -2.0,
	0.0, 2.0
};

const GLushort Card::_diamIdc[] = {
	0, 2, 3,
	2, 3, 1
};

Card::Card(unsigned int suit, bool t, glm::vec2 loc) :
	Obj((GLfloat*) _vtc, (GLushort*) _idc, sizeof _idc / sizeof *_idc, loc, "main", "solid") {
		_noChild++;
		_child = (Obj**) realloc(_child, _noChild * sizeof (Obj*));

		Obj* suitObj = new Obj((GLfloat*) _diamVtc, (GLushort*) _diamIdc, 2 * 3, glm::vec2(0.0), "main", "solid");

		suitObj->_prog.use();

		GLint uniLocSuit = glGetUniformLocation(suitObj->_prog._id, "loc");
		glUniform2fv(uniLocSuit, 1, glm::value_ptr(glm::vec2(0.0)));

		GLint uniTSuit = glGetUniformLocation(suitObj->_prog._id, "t");
		glUniform1ui(uniTSuit, true);

		GLint uniResSuit = glGetUniformLocation(suitObj->_prog._id, "res");
		glUniform2ui(uniResSuit, res[X], res[Y]);

		suitObj->_prog.unUse();

		_child[0] = suitObj;

		/* Program */
		_prog.use();

		// Uniform
		GLint uni[2];

		uni[T] = glGetUniformLocation(_prog._id, "t");
		glUniform1ui(uni[T], t);

		uni[RES] = glGetUniformLocation(_prog._id, "res");
		glUniform2ui(uni[RES], res[X], res[Y]);

		_prog.unUse();
	}
