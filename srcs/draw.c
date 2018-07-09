#include "../includes/header.h"

void	draw(t_sdl *Game)
{
	int a;
	int	b;

	a = 0;
	SDL_SetRenderDrawColor(Game->screen.Renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	while (a < 50)
	{
		SDL_RenderDrawPoint(Game->screen.Renderer, a, a);
		a++;
	}
//	SDL_SetRenderDrawColor(Game->screen.Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}
