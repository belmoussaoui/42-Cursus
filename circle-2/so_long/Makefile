# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 14:14:07 by bel-mous          #+#    #+#              #
#    Updated: 2022/03/21 01:18:00 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = mandatory/main.c mandatory/game.c \
	mandatory/player/player.c mandatory/player/update.c \
	mandatory/minivista/image.c mandatory/minivista/minivista.c \
	mandatory/map/map.c mandatory/map/is_valid.c mandatory/map/draw.c \
	mandatory/map/update.c mandatory/map/error.c

OBJS = $(SRC:.c=.o)
NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror


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