# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 03:32:18 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/03 21:28:58 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c check.c ft_isalpha_test.c ft_isdigit_test.c ft_isalnum_test.c \
	ft_isascii_test.c ft_isprint_test.c ft_strlen_test.c ft_memset_test.c
OBJS_DIR = objs/
OBJS_NAMES = ${SRCS:.c=.o}
OBJS = $(addprefix ${OBJS_DIR}, ${OBJS_NAMES})
LIBFT = libft
NAME = grademe
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: ${LIBFT} ${NAME}

${LIBFT}:
	make -C ../

${NAME}: ${OBJS_DIR} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L../ -lft

$(OBJS_DIR):
	mkdir $@

$(OBJS_DIR)%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I../


clean:
	rm -Rf ./objs

fclean: clean
	rm -f ${NAME}
	make -C ../ fclean

re: fclean all

.PHONY: all clean fclean re