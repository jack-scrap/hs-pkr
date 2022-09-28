#pragma once

#include <string>
#include <GL/glew.h>

#include "util.h"

class Shad {
	public:
		GLuint _id;

		Shad(std::string name, int stage);

		~Shad();
};

class Prog {
	public:
		GLuint _id;

		Prog(std::string nameVtx, std::string nameFrag);

		void use();

		void unUse();

		~Prog();

		enum {
			VTX,
			SHAD
		};
};
