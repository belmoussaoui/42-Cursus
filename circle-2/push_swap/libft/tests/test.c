/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:17:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/29 20:45:20 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

// check makefile
// size_t in str_len.c
// check static in ft_split.c & ft_itoa.c
// check free ft_split.c
// check segfault in part 2 and bonus

int	check_assert(int boolean)
{
	int	res;

	res = -1;
	if (boolean)
	{
		res = 1;
		printf("\033[0;32m");
		printf("OK");
	}
	else
	{
		res = 0;
		printf("\033[0;31m");
		printf("NOK");
	}
	printf("\033[0m");
	return (res);
}

void	ft_strchr_test(void)
{
	char	*str;
	int		c;

	c = 't' + 255;
	str = "tripouille";
	printf("ft_strchr :");
	printf(" ");
	check_assert(ft_strchr(str, c) == strchr(str, c));
	printf("\n");
}

void	ft_atoi_test(void)
{
	char	*n1;
	char	*n2;

	n1 = "-9999999999";
	n2 = "-9999999999999999999999999";
	printf("ft_atoi :");
	printf(" ");
	check_assert(ft_atoi(n1) == atoi(n1));
	printf(" | ");
	check_assert(ft_atoi(n2) == atoi(n2));
	printf("\n");
}

void	ft_substr_test(void)
{
	printf("ft_substr :");
	printf(" ");
	ft_substr(NULL, 0, 10);
}

int	main(void)
{
	printf("part 1 - libc functions\n");
	ft_strchr_test();
	ft_atoi_test();
	return (0);
}
