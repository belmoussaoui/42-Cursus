# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:35:35 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/29 21:06:18 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c specifier.c ft_printnbr.c ft_printstr.c ft_utils.c \
	handle_tags.c padding.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME)

libft:
	make -C ./libft/

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

bonus: libft $(NAME)

clean:
	make clean -C ./libft/
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus