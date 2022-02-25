# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 14:12:01 by bel-mous          #+#    #+#              #
#    Updated: 2022/02/25 20:24:10 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = main.c debug.c game/setup_game.c game/lock_sort.c \
	commands/command_push.c commands/command_reverse.c commands/command_rotate.c \
	commands/command_swap.c
SRC = $(addprefix src/, $(SRC_FILES)) 
OBJS = $(SRC:.c=.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME)

libft:
	make bonus -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus