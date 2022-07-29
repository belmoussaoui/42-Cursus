# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 13:15:26 by bel-mous          #+#    #+#              #
#    Updated: 2021/12/01 19:33:44 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c check_header.c check_map.c data_manager.c file.c position.c process.c utils.c
OBJS = ${SRCS:.c=.o}
NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = ./includes/

.c.o:
	${CC} ${FLAGS} -c $< -o ${.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
	

.PHONY: all clean fclean
