# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 16:10:01 by bel-mous          #+#    #+#              #
#    Updated: 2022/08/15 14:00:14 by vrogiste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = 	main.c \
		event/event.c \
		gameloop/update_cam.c gameloop/gameloop.c \
		parsing/check_map.c parsing/parse.c parsing/parse_map.c parsing/parse_textures.c parsing/get_map_str.c\
		render/dda.c render/raycasting.c render/render.c \
		utils/bits.c utils/mlx_utils.c utils/error.c utils/swap.c utils/ato.c utils/get_next_line.c utils/min_max.c utils/copy.c utils/put.c utils/str.c utils/vector.c utils/split.c utils/str_alloc.c utils/str_arr.c utils/find.c utils/get_next_non_empty_line.c utils/x_alloc.c\
		data_struct/dy_str.c

SRC		:= $(addprefix src/,$(SRC))

INCLUDES = include
OBJ = $(SRC:.c=.o)
CC = gcc

ifeq ($(shell uname), Linux)
	CFLAGS = -I$(INCLUDES) -D LINUX -Wall -Wextra -Werror
	LIB			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
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
	./$(NAME) map/minimalist.cub

.PHONY: all clean fclean re
