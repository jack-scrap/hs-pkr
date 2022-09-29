#include <memory.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "obj.h"

Obj::Obj(GLfloat* vtc, GLushort* idc, unsigned int noEl, glm::vec2 loc, std::string nameVtx, std::string nameFrag, Obj* child, unsigned int noChild) :
	_mesh(vtc, idc, noEl),
	_prog(nameVtx, nameFrag),
	_model(glm::mat4(1.0)),
	_noChild(noChild) {
		/* Matrix */
		_model = glm::translate(_model, glm::vec3(loc, 0.0));

		/* Program */
		_prog.use();

		// Attribute
		GLint attr[1];

		attr[POS] = glGetAttribLocation(_prog._id, "pos");
		glVertexAttribPointer(attr[POS], 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(attr[POS]);

		// Uniform
		GLint uni[1];

		uni[MODEL] = glGetUniformLocation(_prog._id, "model");
		glUniformMatrix4fv(uni[MODEL], 1, GL_FALSE, glm::value_ptr(_model));

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
