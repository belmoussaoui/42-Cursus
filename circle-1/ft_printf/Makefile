# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:35:35 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/14 13:55:40 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_printf.c
OBJS = $(SRCS:.c=.o)
NAME = main.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I./libft/

all: libft $(NAME)

libft:
	make -C ./libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft/ -lft

clean:
	make clean -C ./libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft