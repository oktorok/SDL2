#include "../includes/header.h"

static int	set_flags(int argn, char **argv)
{
	int	i[2];
	int	flag;

	flag = 0;
	i[0] = 1;
	while (i[0] < argn)
	{
		i[1] = 0;
		if (argv[i[0]][i[1]] == '-')
		{
			while (argv[i[0]][++i[1]])
			{
				if (argv[i[0]][i[1]] >= 97 && argv[i[0]][i[1]] <= 122)
					flag = flag | (1 << (argv[i[0]][i[1]] - 97));
			}
		}
		i[0]++;
	}
	for(int j = 0; j < 32; j++)
	{
		if (flag & (1 << j))
			printf("%i", 1);
		else
			printf("%i", 0);
	}
	printf("\n");
	return (flag);
}

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
