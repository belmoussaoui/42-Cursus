# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 14:12:01 by bel-mous          #+#    #+#              #
#    Updated: 2022/03/14 17:47:30 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = main.c setup/setup_game.c setup/setup_numbers.c game/lock_sort.c \
	game/lock_rotate.c game/lock_action.c game/twin_sort.c \
	commands/command_push.c commands/command_reverse.c commands/command_rotate.c \
	commands/command_swap.c
BONUS_FILES = checker/checker.c checker/interpreter.c setup/setup_game.c \
	setup/setup_numbers.c commands/command_push.c commands/command_reverse.c \
	commands/command_rotate.c commands/command_swap.c

SRC = $(addprefix src/, $(SRC_FILES))
BONUS = $(addprefix src/, $(BONUS_FILES)) 

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: libft $(NAME)

libft:
	make bonus -C ./libft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

bonus: libft $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus