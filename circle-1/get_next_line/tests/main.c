/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:28:15 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/26 23:40:30 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../get_next_line.h"
#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("alhambra.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	//	printf("%s\n", line);
	}
	// close(fd);
	// get_next_line(fd);
	//system("leaks grademe.out");
	return (0);
}