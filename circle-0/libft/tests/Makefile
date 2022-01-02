# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 03:32:18 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/02 05:01:46 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = main.c check.c ft_strlen_test.c
OBJS = ${SRCS:.c=.o}
LIB = libft
NAME = grademe
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I../

all: ${LIB} ${NAME}

${LIB}:
	make -C ../

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L../ -lft

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re