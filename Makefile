.PHONY: all clean fclean re

NAME = tutorial_SDL2
SRC_DIR = srcs/
INCLUDES_DIR = includes/
OBJ_DIR = objects/
CFLAGS =
SDLFLAGS = -lSDL2
SRC =	game_init.c \
		game_quit.c \
		main.c \
		check_flags.c
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
