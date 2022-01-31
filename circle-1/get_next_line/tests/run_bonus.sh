# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_bonus.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 13:41:25 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/30 21:07:39 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#echo "check norminette :"
#norminette ../*.c

if [ -z "$1" ] ; then
	echo "BUFFER_SIZE is undefined\n"
else
	gcc -Wall -Werror -Wextra test_bonus.c -o test_bonus.out -g ../*_bonus.c -D BUFFER_SIZE=$1
	./test_bonus.out
fi