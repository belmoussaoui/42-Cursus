# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:42:07 by bel-mous          #+#    #+#              #
#    Updated: 2022/04/17 13:56:14 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/main.c mandatory/setup.c mandatory/run.c utils/ft_utils.c \
	utils/ft_split.c
SRCS_BONUS = bonus/main.c bonus/setup.c bonus/run.c bonus/heredoc.c \
	utils/ft_utils.c utils/ft_split.c utils/get_next_line.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus