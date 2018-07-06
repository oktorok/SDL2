#include "../includes/header.h"

void game_quit(t_sdl *Game)
{
	SDL_DestroyRenderer(Game->screen.Renderer);
	SDL_DestroyWindow(Game->screen.window);
	printf("Game_quit\n");
	SDL_Quit();
	Game->running = SDL_FALSE;
}
