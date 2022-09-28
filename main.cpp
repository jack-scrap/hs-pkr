#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "disp.h"
#include "prog.h"
#include "util.h"
#include "card.h"
#include "math.h"

extern const unsigned int res[2] = {
	800,
	600
};

int main() {
	Disp disp("Poker", res[X], res[Y]);
	
	Card card(false, glm::vec2(0.0, 5.0));

	SDL_Event e;
	while (disp.open) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
			}
		}

		disp.clear(0, 0, 0, 1);

		card.draw();

		disp.update();
	}
}
