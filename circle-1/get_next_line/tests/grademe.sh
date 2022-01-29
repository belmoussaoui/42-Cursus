# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grademe.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 13:41:25 by bel-mous          #+#    #+#              #
#    Updated: 2022/01/29 09:35:02 by bel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#echo "check norminette :"
#norminette ../*.c

echo ""
if [ -z "$1" ] ; then
	echo "BUFFER_SIZE is undefined\n"
else
	gcc main.c -o grademe.out -g ../get_next_line.c ../get_next_line_utils.c -D BUFFER_SIZE=$1
	#gcc main.c -o grademe.out ../get_next_line_bonus.c ../get_next_line_utils_bonus.c -D BUFFER_SIZE=$1
	./grademe.out
fi