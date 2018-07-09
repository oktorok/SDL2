#include "../includes/header.h"

void	change_background(t_sdl *Game)
{
	static int	color = 1;

	if (color == 1)
	{
		SDL_SetRenderDrawColor(Game->screen.Renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		color = 2;
	}
	else if (color == 2)
	{
		SDL_SetRenderDrawColor(Game->screen.Renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
		color = 3;
	}
	else if (color == 3)
	{
		SDL_SetRenderDrawColor(Game->screen.Renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
		color = 1;
	}
}
