#include "../includes/header.h"

int	main(int argn, char **argv)
{
	t_sdl Game;
	SDL_Event event;

	Game = (t_sdl){set_flags(argn, argv), SDL_FALSE, {SCREEN_SCALE * SCREEN_w, SCREEN_SCALE * SCREEN_H, SCREEN_NAME, NULL, NULL}, game_init, game_quit};
	Game.init(&Game);
	while (Game.running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				Game.running = SDL_FALSE;
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					Game.running = SDL_FALSE;
			}
		}
		SDL_RenderClear(Game.screen.Renderer);
		SDL_RenderPresent(Game.screen.Renderer);
	}
	Game.quit(&Game);
	return (0);
}
