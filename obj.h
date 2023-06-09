#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "mesh.h"
#include "prog.h"

class Obj {
	public:
		Mesh _mesh;

		Prog _prog;

		glm::mat4 _model;
		glm::mat4 _acc;

		Obj** _child;
		unsigned int _noChild;

		Obj(GLfloat* vtc, GLushort* idc, unsigned int noEl, std::string nameVtx, std::string nameFrag, glm::vec2 loc = glm::vec2(0.0), Obj* child = nullptr, unsigned int noChild = 0);

		void acc(glm::mat4 prev);

		void draw();

		enum {
			POS
		};

		enum {
			ACC
		};
};
