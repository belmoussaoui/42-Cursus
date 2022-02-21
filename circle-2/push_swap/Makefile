# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 14:12:01 by bel-mous          #+#    #+#              #
#    Updated: 2022/02/20 15:31:42 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c setup.c debug.c instructions.c
OBJS = $(SRCS:.c=.o)
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