#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "card.h"
#include "math.h"

extern const unsigned int res[2];

const GLfloat Card::_dim[2] = {
	2.5,
	3.5
};

const GLfloat Card::_vtc[2 * 2 * 2] = {
	-Card::_dim[X] / 2, -Card::_dim[Y] / 2,
	Card::_dim[X] / 2, -Card::_dim[Y] / 2,
	-Card::_dim[X] / 2, Card::_dim[Y] / 2,
	Card::_dim[X] / 2, Card::_dim[Y] / 2
};

const GLushort Card::_idc[2 * 3] = {
	0, 1, 2,
	2, 1, 3
};

const GLfloat Card::_spadeVtc[] = {
	-2.0, 0.0,
	2.0, 0.0,
	0.0, 2.0,

	-1.0, -1.0,
	1.0, -1.0,
	0.0, 0.0
};

const GLushort Card::_spadeIdc[] = {
	0, 1, 2,
	3, 4, 5
};

const GLfloat Card::_heartVtc[] = {
	-1.0, 0.0,
	1.0, 0.0,
	0.0, -1.0,
	0.0, 1.0,

	-2.0, 1.0,
	0.0, 1.0,
	-1.0, 0.0,
	-1.0, 2.0,

	0.0, 1.0,
	2.0, 1.0,
	1.0, 0.0,
	1.0, 2.0
};

const GLushort Card::_heartIdc[] = {
	0, 1, 2,
	0, 1, 3,

	4, 5, 6,
	4, 5, 7,

	8, 9, 10,
	8, 9, 11
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

Card::Card(unsigned int no, unsigned int suit, bool t, glm::vec2 loc) :
	Obj((GLfloat*) _vtc, (GLushort*) _idc, sizeof _idc / sizeof *_idc, "main", "solid", loc) {
		/* Suit */
		_noChild++;
		_child = (Obj**) realloc(_child, _noChild * sizeof (Obj*));

		Obj* suitObj = new Obj((GLfloat*) _diamVtc, (GLushort*) _diamIdc, sizeof _diamIdc / sizeof *_diamIdc, "main", "solid", glm::vec2(0.0));

		suitObj->_prog.use();

		GLint uniTSuit = glGetUniformLocation(suitObj->_prog._id, "t");
		glUniform1ui(uniTSuit, true);

		GLint uniResSuit = glGetUniformLocation(suitObj->_prog._id, "res");
		glUniform2ui(uniResSuit, res[X], res[Y]);

		suitObj->_prog.unUse();

		_child[0] = suitObj;

		acc(glm::mat4(1.0));

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
