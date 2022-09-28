#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "disp.h"
#include "prog.h"
#include "util.h"
#include "mesh.h"
#include "card.h"
#include "obj.h"
#include "math.h"

extern const unsigned int res[2] = {
	800,
	600
};

int main() {
	Disp disp("Poker", res[X], res[Y]);
	
	std::vector<Card*> hand[2];
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < 5; i++) {
			hand[t].push_back(new Card(t, glm::vec2(i * 2.0, (t ? 1 : -1) * 5.0)));
		}
	}

	SDL_Event e;
	while (disp.open) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_Quit();
			}
		}

		disp.clear(0, 0, 0, 1);

		for (int t = 0; t < 2; t++) {
			for (Card* card : hand[t]) {
				card->draw();
			}
		}

		disp.update();
	}
}
