#pragma once

#include "util.h"

class Shad {
	public:
		GLuint _id;

		Shad(std::string name, bool vtx);

		~Shad();
};

class Prog {
	public:
		GLuint _id;

		Prog(std::string nameVtx, std::string nameFrag);

		void use();

		void unUse();

		~Prog();
};
