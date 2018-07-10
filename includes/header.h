#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_w 674
#define SCREEN_H 286
#define SCREEN_SCALE 1
#define SCREEN_NAME "Prototype"

typedef struct s_sdl {
	int		flags;
	SDL_bool running;
	struct {
		int w;
		int h;
		const char *name;
		SDL_Window *window;
		SDL_Renderer *Renderer;
	} screen;
	void (*init)(struct s_sdl *);
	void (*quit)(struct s_sdl *);
} t_sdl;

void	texto(t_sdl *Game);
void	draw(t_sdl *Game);
void	change_background(t_sdl *Game);
void	game_init(t_sdl *Game);
void	game_quit(t_sdl *Game);
int		check_flags(int flags, char flag);
int		set_flags(int argn, char **argv);
#endif
