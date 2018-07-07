#include "../includes/header.h"
#include "unistd.h"

void game_init(t_sdl *Game)
{
	printf("Game_init\n");

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	if (!(Game->screen.window = SDL_CreateWindow(Game->screen.name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game->screen.w, Game->screen.h, SDL_WINDOW_RESIZABLE)))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	if (check_flags(Game->flags, 'f') && SDL_SetWindowFullscreen(Game->screen.window, SDL_WINDOW_FULLSCREEN_DESKTOP))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	else
		SDL_GetWindowSize(Game->screen.window, &(Game->screen.w), &(Game->screen.h));
	if (!(Game->screen.Renderer = SDL_CreateRenderer(Game->screen.window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC)))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	Game->running = SDL_TRUE;
	printf("La ventana mide %i x %i\n", Game->screen.w, Game->screen.h);
}
