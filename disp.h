#include <string>
#include <iostream>

#include <GL/glew.h>
#include <SDL2/SDL.h>

class Disp {
	private:
		SDL_Window* _win;

		SDL_GLContext _ctx;

	public:
		bool open = false;

		Disp(const char* title, int wd, int ht);

		void clear(float r, float g, float b, float a);

		void update();

		~Disp();
};
