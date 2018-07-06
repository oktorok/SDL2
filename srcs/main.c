#include "header.h"

int	main(int argn, char **argv)
{
	t_sdl Game;
	SDL_Event event;
	SDL_Rect rect;
	SDL_Texture *texture1;
	SDL_Texture *texture2;
	SDL_Texture *texture3;
	SDL_Texture *texture4;
	int x;
	int y;

	Game = (t_sdl){SDL_FALSE,{SCREEN_SCALE * SCREEN_w, SCREEN_SCALE * SCREEN_H, SCREEN_NAME, NULL, NULL}, {0, NULL}, game_init, game_quit};
	Game.init(&Game);

	x = Game.screen.w / 2 - 8;
	y = Game.screen.h / 2 - 8;
	rect = (SDL_Rect){0, 0, 8 * 2, 8 * 2};
	texture1 = SDL_CreateTextureFromSurface(Game.screen.Renderer, Game.gfx.spritesheet[17]);
	texture2 = SDL_CreateTextureFromSurface(Game.screen.Renderer, Game.gfx.spritesheet[18]);
	texture3 = SDL_CreateTextureFromSurface(Game.screen.Renderer, Game.gfx.spritesheet[29]);
	texture4 = SDL_CreateTextureFromSurface(Game.screen.Renderer, Game.gfx.spritesheet[30]);
	while (Game.running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				Game.running = SDL_FALSE;
		}

		SDL_RenderClear(Game.screen.Renderer);
		rect.x = 0+x;
		rect.y = 0+y;
		SDL_RenderCopy(Game.screen.Renderer, texture1, NULL, &rect);

//		rect.x = 8*2+x;
//		rect.y = 0+y;
//		SDL_RenderCopy(Game.screen.Renderer, texture2, NULL, &rect);
//		rect.x = 0+x;
//		rect.y = 8*2+y;
//		SDL_RenderCopy(Game.screen.Renderer, texture3, NULL, &rect);
//
//		rect.x = 8*2+x;
//		rect.y = 8*2+y;
//		SDL_RenderCopy(Game.screen.Renderer, texture4, NULL, &rect);
//
		SDL_RenderPresent(Game.screen.Renderer);
		SDL_RenderPresent(Game.screen.Renderer);
	}
	SDL_DestroyTexture(texture1);
	SDL_DestroyTexture(texture2);
	SDL_DestroyTexture(texture3);
	SDL_DestroyTexture(texture4);
	Game.quit(&Game);
	return (0);
}
