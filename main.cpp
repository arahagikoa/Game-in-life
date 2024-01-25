
#include <SDL2/SDL.h>
#include <ctime>
#include <iostream>
#include "cell_map.h"
#define OFF_COLOUR 0x00
#define ON_COLOUR 0xFF
#define LIMIT_RATE 0
#define TICK_RATE 50


unsigned int cellmap_width = 500;
unsigned int cellmap_height = 500;

unsigned int cell_size = 1;


SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
unsigned int s_width = cellmap_width * cell_size;
unsigned int s_height = cellmap_height * cell_size;


void DrawCell(unsigned int x, unsigned int y, unsigned int colour)
{
	Uint8* pixel_ptr = (Uint8*)surface->pixels + (y * cell_size * s_width + x * cell_size) * 4;

	for (unsigned int i = 0; i < cell_size; i++)
	{
		for (unsigned int j = 0; j < cell_size; j++)
		{
			*(pixel_ptr + j * 4) = colour;
			*(pixel_ptr + j * 4 + 1) = colour;
			*(pixel_ptr + j * 4 + 2) = colour;
		}
		pixel_ptr += s_width * 4;
	}
}

int WinMain(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game in Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, s_width, s_height, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	unsigned long generation = 0;

	CellMap current_map(cellmap_width, cellmap_height);
	current_map.Init();

	SDL_Event e;

	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
			if (e.type == SDL_QUIT) quit = true;

		generation++;

		current_map.NextGen();
		SDL_UpdateWindowSurface(window);

#if LIMIT_RATE
		SDL_Delay(TICK_RATE);
#endif
	}

	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}
