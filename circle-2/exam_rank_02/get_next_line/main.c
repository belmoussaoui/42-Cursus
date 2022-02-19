/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:51:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/19 19:06:25 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	
	char *line = get_next_line(fd);
	printf("%s", line);
	
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
