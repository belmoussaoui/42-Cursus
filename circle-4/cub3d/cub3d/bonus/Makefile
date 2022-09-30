NAME = cub3D

SRC = 	main.c \
		event/quit.c event/event.c\
		gameloop/door.c gameloop/update_cam.c gameloop/gameloop.c gameloop/enemy_shot.c \
		parsing/check_map.c parsing/parse.c parsing/parse_map.c parsing/parse_textures.c parsing/get_map_str.c parsing/parse_sprite.c parsing/parse_enemy.c \
		render/routines.c render/skycasting.c render/floorcasting.c render/dda.c render/raycasting.c render/hud.c render/minimap.c render/render.c\
		utils/mlx_utils.c utils/utils.c utils/get_next_line.c utils/min_max.c utils/copy.c utils/put.c utils/str.c  utils/split.c utils/str_alloc.c utils/str_arr.c utils/find.c utils/get_next_non_empty_line.c utils/x_alloc.c\
		utils/thread.c utils/swap.c utils/mouse_move.c utils/error.c utils/color.c utils/blt.c utils/sound.c \
		data_struct/vector_norme.c data_struct/circular_lst.c data_struct/dy_str_insert.c data_struct/node.c data_struct/lst.c data_struct/dy_str.c data_struct/vector.c\
		sprite/sprite.c sprite/draw_sprite.c sprite/gun.c sprite/init_gun.c sprite/collectible.c scene/title.c scene/title_draw.c \
		enemy/enemy.c\
		gameloop/update_enemy.c

ifneq ($(shell uname), Linux)
	SRC +=	utils/mlx_mouse.m
endif

SRC		:= $(addprefix src/,$(SRC))

INCLUDES = include
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)
CC = gcc

ifeq ($(shell uname), Linux)
	CFLAGS = -I$(INCLUDES) -D LINUX -Wall -Wextra -Werror
	LIB			= -lpthread	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -D MAC
	LIB = -lmlx -framework OpenGL -framework AppKit
endif


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) map/custom.cub

.PHONY: all clean fclean re
