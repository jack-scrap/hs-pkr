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
		Card(bool t, glm::vec2 loc = glm::vec2(0.0));

		void draw();
};
