#pragma once

#include <GL/glew.h>

#include "mesh.h"
#include "prog.h"

class Obj {
	public:
		Mesh _mesh;

		Prog _prog;

		Obj(GLfloat* vtc, GLushort* idc, unsigned int noEl, std::string nameVtx, std::string nameFrag);

		void draw();

		enum {
			POS
		};
};
