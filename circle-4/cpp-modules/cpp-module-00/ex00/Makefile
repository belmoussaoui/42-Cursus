# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 17:48:58 by bel-mous          #+#    #+#              #
#    Updated: 2022/07/07 20:17:34 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone
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

test: $(NAME)
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

.PHONY: all clean fclean re