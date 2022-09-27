#pragma once

#include <GL/glew.h>

#include "prog.h"

class Card {
	private:
		GLuint _vao;

		Prog _prog;

		static const GLfloat _vtc[2 * 2 * 2];

		static const GLushort _idc[2 * 3];

	public:
		Card(bool t);

		void draw();
};
