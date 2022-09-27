#include <iostream>
#include <string>

#include <GL/glew.h>

#include "prog.h"
#include "util.h"

Shad::Shad(std::string name, bool vtx) {
	std::string ext;
	GLenum type;
	if (vtx) {
		ext = "vs";
		type = GL_VERTEX_SHADER;
	} else {
		ext = "fs";
		type = GL_FRAGMENT_SHADER;
	}

	std::string path = std::string(name) + std::string(".") + ext;

	std::string txt = util::rd(path);
	const char* src = txt.c_str();

	GLint succ;
	char buff[] = "";

	_id = glCreateShader(type);
	glShaderSource(_id, 1, &src, NULL);
	glCompileShader(_id);

	glGetShaderiv(_id, GL_COMPILE_STATUS, &succ);
	if (!succ) {
		glGetShaderInfoLog(_id, 512, NULL, buff);
		std::cout << "Error: " << std::endl;
		std::cout << buff << std::endl;
	}
}

Shad::~Shad() {
	glDeleteShader(_id);
}

Prog::Prog(std::string nameVtx, std::string nameFrag) {
	/* shader */
	/// vertex
	Shad vtx("res/shad/" + nameVtx, 1);

	/// fragment
	Shad frag("res/shad/" + nameFrag, 0);

	/// program
	_id = glCreateProgram();
	glAttachShader(_id, vtx._id);
	glAttachShader(_id, frag._id);
	glLinkProgram(_id);
}

void Prog::use() {
	glUseProgram(_id);
}

void Prog::unUse() {
	glUseProgram(0);
}

Prog::~Prog() {
	glDeleteProgram(_id);
}
