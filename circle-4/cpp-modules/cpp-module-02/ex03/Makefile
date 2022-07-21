# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 10:41:39 by bel-mous          #+#    #+#              #
#    Updated: 2022/07/21 20:56:08 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = bsp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re