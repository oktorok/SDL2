#include "header.h"
#include "unistd.h"

void game_init(t_sdl *Game)
{
	printf("Game_init\n");

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	if (!(Game->screen.window = SDL_CreateWindow(Game->screen.name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game->screen.w, Game->screen.h, 0)))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_SetWindowFullscreen(Game->screen.window, SDL_WINDOW_FULLSCREEN))
	{
		printf("SDL_error -> %s\n", SDL_GetError());
		exit(1);
	}
	if (!(Game->screen.Renderer = SDL_CreateRenderer(Game->screen.window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC)))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	Game->running = SDL_TRUE;
}
