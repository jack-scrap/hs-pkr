#pragma once

#include <GL/glew.h>

#include "mesh.h"
#include "prog.h"

class Card {
	private:
		Mesh _mesh;

		Prog _prog;

		static const GLfloat _vtc[2 * 2 * 2];

		static const GLushort _idc[2 * 3];

		enum {
			SPACE,
			CLUB,
			HEART,
			DIAM
		};

	public:
		Card(bool t, glm::vec2 loc = glm::vec2(0.0));

		void draw();
};
