#pragma once

#include <GL/glew.h>

#include "obj.h"
#include "prog.h"

class Card : public Obj {
	private:
		static const GLfloat _vtc[2 * 2 * 2];

		static const GLushort _idc[2 * 3];

		static const GLfloat _diamVtc[];

		static const GLushort _diamIdc[];

		enum {
			SPACE,
			CLUB,
			HEART,
			DIAM
		};

		enum {
			LOC,
			T,
			RES
		};

	public:
		Card(bool t, glm::vec2 loc = glm::vec2(0.0));
};
