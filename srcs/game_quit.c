#include "header.h"

void game_quit(t_sdl *Game)
{
	for(int i=0; i<Game->gfx.n; i++)
		SDL_FreeSurface(Game->gfx.spritesheet[i]);
	free(Game->gfx.spritesheet);
	SDL_DestroyRenderer(Game->screen.Renderer);
	SDL_DestroyWindow(Game->screen.window);
	printf("Game_quit\n");
	SDL_Quit();
	Game->running = SDL_FALSE;
}
