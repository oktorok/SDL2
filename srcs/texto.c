#include "../includes/header.h"

void	texto(t_sdl *Game)
{
	TTF_Font	*font;
	SDL_Color	color;
	SDL_Surface	*texto;
	SDL_Texture	*texto_tex;
	SDL_Rect	box;

	if (TTF_Init() < 0)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	color = (SDL_Color){0, 0, 0, 255};
	if (!(font = TTF_OpenFont("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", 100)))
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit (2);

	}
	if (!(texto = TTF_RenderUTF8_Solid(font, "A", color)))
	{
		printf("TTF_RenderUTF8_Solid: %s\n", TTF_GetError());
		exit (2);
	}
	TTF_SizeText(font, "A", &box.w, &box.h);
	printf("El texto mide %i x %i\n", box.w, box.h);
	TTF_CloseFont(font);
	texto_tex = SDL_CreateTextureFromSurface(Game->screen.Renderer, texto);
	SDL_FreeSurface(texto);
	box = (SDL_Rect){0, 0, 0, 0};
	SDL_QueryTexture(texto_tex, NULL, NULL, &box.w, &box.h);
	printf("La textura mide %i x %i\n", box.w, box.h);
	SDL_RenderCopy(Game->screen.Renderer, texto_tex, NULL, &box);
	SDL_DestroyTexture(texto_tex);
	TTF_Quit();
}
