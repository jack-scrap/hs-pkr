#include <memory.h>

#include "obj.h"

Obj::Obj(GLfloat* vtc, GLushort* idc, unsigned int noEl, std::string nameVtx, std::string nameFrag, Obj* child, unsigned int noChild) :
	_mesh(vtc, idc, noEl),
	_prog(nameVtx, nameFrag),
	_noChild(noChild) {
		/* Program */
		_prog.use();

		// Attribute
		GLint attr[1];

		attr[POS] = glGetAttribLocation(_prog._id, "pos");
		glVertexAttribPointer(attr[POS], 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(attr[POS]);

		_prog.unUse();

		/* Children */
		_child = (Obj**) malloc(_noChild * sizeof (Obj*));
	}

void Obj::draw() {
	glBindVertexArray(_mesh._vao);
	_prog.use();

	glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_SHORT, (GLvoid*) 0);

	_prog.unUse();
	glBindVertexArray(0);

	for (int i = 0; i < _noChild; i++) {
		_child[i]->draw();
	}
}
