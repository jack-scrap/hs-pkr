#include <iostream>
#include <string>
#include <GL/glew.h>

#include "prog.h"
#include "util.h"

Shad::Shad(std::string name, int stage) {
	std::string ext;
	GLenum type;

	switch (stage) {
		case 0:
			ext = "fs";
			type = GL_FRAGMENT_SHADER;

			break;

		case 1:
			ext = "vs";
			type = GL_VERTEX_SHADER;

			break;
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
	// Vertex
	Shad vtx("res/shad/" + nameVtx, 1);

	// Fragment
	Shad frag("res/shad/" + nameFrag, 0);

	// Program
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
