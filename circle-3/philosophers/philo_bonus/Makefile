# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 17:48:58 by bel-mous          #+#    #+#              #
#    Updated: 2022/05/26 17:59:49 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c setup.c check_arg.c exit.c philo.c check_dead.c time.c clear.c
OBJS = $(SRCS:.c=.o)
NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re