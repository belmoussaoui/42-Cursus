# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 13:41:25 by bel-mous          #+#    #+#              #
#    Updated: 2022/02/03 13:23:47 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#echo "check norminette :"
#norminette ../*.c

# if [ -z "$1" ] ; then
# 	echo "BUFFER_SIZE is undefined"
# else
	gcc -Wall -Werror -Wextra test.c -o test.out -g ./get_next_line.c ./get_next_line_utils.c -D BUFFER_SIZE=10000000
	./test.out
# fi