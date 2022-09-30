#pragma once

#include <GL/glew.h>

#include "obj.h"
#include "prog.h"

class Card : public Obj {
	private:
		static const GLfloat _vtc[2 * 2 * 2];
		static const GLushort _idc[2 * 3];

		static const GLfloat _spadeVtc[];
		static const GLushort _spadeIdc[];

		static const GLfloat _heartVtc[];
		static const GLushort _heartIdc[];

		static const GLfloat _diamVtc[];
		static const GLushort _diamIdc[];

		enum {
			T,
			RES
		};

	public:
		Card(unsigned int no, unsigned int suit, bool t, glm::vec2 loc);

		enum {
			ACE,
			JACK = 11,
			QUEEN,
			KING
		};

		enum {
			SPACE,
			CLUB,
			HEART,
			DIAM
		};
};
