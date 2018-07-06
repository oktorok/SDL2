#include "header.h"
#include "unistd.h"
static void ini_surface(t_sdl *Game)
{
	int i;
	int x;
	int y;
	SDL_Surface *surface;
	SDL_Rect rect = {0, 0, 8, 8};

	if (!(surface = SDL_LoadBMP("srcs/spritesheet.bmp")))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}
	printf("surface vale %d x %d\n", surface->w, surface->h);
	Game->gfx.n = ((surface->w / 8) * (surface->h / 8) + 1);
Game->gfx.spritesheet = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * Game->gfx.n);
	write(1, "CACA", 4);

	for(i = 0; i < Game->gfx.n; i++)
	{
		Game->gfx.spritesheet[i] = SDL_CreateRGBSurface(0, 8, 8, 24, 0x00, 0x00, 0x00, 0x00);
		SDL_SetColorKey(Game->gfx.spritesheet[i], 1, 0xFF00FF);
		SDL_FillRect(Game->gfx.spritesheet[i], 0, 0xFF00FF);
		if (i)
		{
			x = (i - 1) % (surface->w / 8);
			y = (i - x) / (surface->w / 8);
			rect.x = x * 8;
			rect.y = y * 8;
			SDL_BlitSurface(surface, &rect, Game->gfx.spritesheet[i], NULL);
		}
	}
	SDL_FreeSurface(surface);
}

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
	if (!(Game->screen.Renderer = SDL_CreateRenderer(Game->screen.window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC)))
	{
		printf("SDL error -> %s\n", SDL_GetError());
		exit(1);
	}

	ini_surface(Game);
	Game->running = SDL_TRUE;
}
