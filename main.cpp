#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "disp.h"
#include "prog.h"
#include "util.h"

int main() {
	Disp disp("asdf", 800, 600);

	/* data */
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Position
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	const GLfloat vtc[2 * 2 * 2] = {
		-1.0, -2.0,
		1.0, -2.0,
		-1.0, 2.0,
		1.0, 2.0
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof vtc, vtc, GL_STATIC_DRAW);

	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	const GLushort idc[] = {
		0, 1, 2,
		2, 1, 3
	};

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof idc, idc, GL_STATIC_DRAW);

	/* Shader */
	Prog prog("main", "solid");

	// Attribute
	GLint attrPos = glGetAttribLocation(prog._id, "pos");
	glVertexAttribPointer(attrPos, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
	glEnableVertexAttribArray(attrPos);

	prog.use();

	SDL_Event e;
	while (disp.open) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
			}
		}

		disp.clear(0, 0, 0, 1);

		glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_SHORT, (GLvoid*) 0);

		disp.update();
	}

	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &vbo);
}
