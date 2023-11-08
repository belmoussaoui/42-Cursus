# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 18:34:56 by bel-mous          #+#    #+#              #
#    Updated: 2023/11/06 16:20:25 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# need to change docker-compose.yml !
DIR = $(HOME)/data

all: up

dir:
	mkdir -p $(DIR)/wordpress
	mkdir -p $(DIR)/database

up: dir
	docker compose --project-directory srcs up -d

build: dir
	docker compose --project-directory srcs up -d --build

down:
	docker compose --project-directory srcs down

fclean:
	docker system prune -fa --volumes

re: down build dir

.PHONY: all clean fclean re