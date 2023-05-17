# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 12:27:37 by bel-mous          #+#    #+#              #
#    Updated: 2023/05/17 18:24:24 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

.PHONY: all clean fclean re