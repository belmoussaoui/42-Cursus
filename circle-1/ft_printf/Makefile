# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:35:35 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/15 13:28:39 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c conversion.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I./libft/

all: libft $(NAME)

libft:
	make -C ./libft/

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) libft/objs/*.o

clean:
	make clean -C ./libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft