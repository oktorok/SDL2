#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"

#define SCREEN_w 640
#define SCREEN_H 480
#define SCREEN_SCALE 1
#define SCREEN_NAME "Prototype"

typedef struct s_sdl {
	int		flags;
	SDL_bool running;
	struct {
		unsigned int w;
		unsigned int h;
		const char *name;
		SDL_Window *window;
		SDL_Renderer *Renderer;
	} screen;
	void (*init)(struct s_sdl *);
	void (*quit)(struct s_sdl *);
} t_sdl;

void	game_init(t_sdl *Game);
void	game_quit(t_sdl *Game);
int		check_flags(int flags, char flag);
#endif
