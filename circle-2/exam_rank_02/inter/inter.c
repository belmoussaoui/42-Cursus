/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:04:50 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/19 14:25:45 by bel-mous         ###   ########.fr       */
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

void inter(char *str1, char *str2)
{
	char res[128];
	int i = 0;
	int j = 0;

	res[0] = '\0';
	while (*str1)
	{
		j = 0;
		while (str2[j])
		{
			if (*str1 == str2[j] && is_valid(*str1, res))
			{
				write(1, str1, 1);
				res[i] = *str1;
				res[i + 1] = '\0';
				i++;
			}
			j++;
		}
		str1++;
	}
}


int	main(int argc, char** argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}
