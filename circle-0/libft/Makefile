# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 03:47:54 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/04 20:05:55 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c

OBJS_DIR = objs/
OBJS_NAMES = ${SRCS:.c=.o}
OBJS = $(addprefix ${OBJS_DIR}, ${OBJS_NAMES})
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS_DIR} ${OBJS}
	ar rcs $(NAME) $(OBJS)

${OBJS_DIR}:
	mkdir $@

$(OBJS_DIR)%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re