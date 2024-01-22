#ifndef __SCREEN__
#define __SCREEN__

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>



class screen {
	int width, height, res;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	screen(int width, int height) {
		this->width = width;
		this->height = height;
		res = height / width;


		window = SDL_CreateWindow("Game in Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	};
	~screen() {
		if (renderer != nullptr){
			SDL_DestroyRenderer(renderer);
			renderer = nullptr;
		}
		if (window != nullptr) {
			SDL_DestroyWindow(window);
			window = nullptr;

		}
		


		SDL_Quit();
	};
	void drawPixel(int x, int y, int state);
	void drawBoard(int width, int height);
};

#endif