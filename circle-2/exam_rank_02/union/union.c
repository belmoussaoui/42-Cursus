/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:07:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/19 13:59:10 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_valid(char c, char *res)
{
	while (*res)
	{
		if (*res == c)
			return (0);
		res++;
	}
	return (1);
}

void ft_union(char *str1, char *str2)
{
	int i = 0;
	char res[128];

	res[0] = '\0';
	while (*str1)
	{
		if (is_valid(*str1, res))
		{
			res[i] = *str1;
			res[i + 1] = '\0';
			i++;
		}
		str1++;
	}
	while (*str2)
	{
		if (is_valid(*str2, res))
		{
			res[i] = *str2;
			res[i + 1] = '\0';
			i++;
		}
		str2++;
	}
	i = 0;
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
}

int	main(int argc, char** argv)
{
	if (argc == 3) {
		ft_union(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
