# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 14:14:07 by bel-mous          #+#    #+#              #
#    Updated: 2022/03/13 22:16:23 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = src/main.c src/input.c src/player/player.c src/map/map.c src/minivista/sprite.c src/minivista/play.c \
	src/minivista/game_loop.c

OBJS = $(SRC:.c=.o)
NAME = so_long

CC = gcc
CFLAGS = #-Wall -Wextra -Werror


all: libft $(NAME)

libft:
	make bonus -C ./libft

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(OBJS) -lm -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus