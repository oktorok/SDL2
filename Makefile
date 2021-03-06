.PHONY: all clean fclean re

NAME = tutorial_SDL2
SRC_DIR = srcs/
INCLUDES_DIR = includes/
OBJ_DIR = objects/
CFLAGS = `sdl2-config --cflags`
SDLFLAGS = `sdl2-config --libs` -lSDL2_ttf
SRC =	game_init.c \
		game_quit.c \
		main.c \
		flags.c \
		change_background.c \
		draw.c \
		texto.c

HEADERS = header.h

HEADERS_PATH = $(patsubst %.h, $(INCLUDES_DIR)%.h, $(HEADERS))
OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(SDLFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS_PATH)
	gcc $(CFLAGS) -I $(INCLUDES_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

clean:
	rm -f $(NAME)

fclean: clean
	rm -frv $(OBJ_DIR)

re: fclean all
