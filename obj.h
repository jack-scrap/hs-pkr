#pragma once

#include <GL/glew.h>

#include "mesh.h"
#include "prog.h"

class Obj {
	public:
		Mesh _mesh;

		Prog _prog;

		Obj** _child;
		unsigned int _noChild;

		Obj(GLfloat* vtc, GLushort* idc, unsigned int noEl, std::string nameVtx, std::string nameFrag, Obj* child = nullptr, unsigned int noChild = 0);

		void draw();

		enum {
			POS
		};
};
