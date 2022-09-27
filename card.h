#pragma once

#include <GL/glew.h>

#include "prog.h"

class Card {
	private:
		GLuint _vao;

		Prog _prog;

	public:
		Card();

		void draw();
};
