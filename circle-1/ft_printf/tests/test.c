/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:10:45 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/30 21:07:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <stddef.h>

void	str_test(void)
{
	printf("str tests\n");
	ft_printf("%d\n", ft_printf("%7.7s%7.7s\n", "hello", "world"));
	printf("%d\n", printf("%7.7s%7.7s\n", "hello", "world"));
	printf("\n");
	ft_printf("%d\n", ft_printf("%-10.5s.\n", (char *) NULL));
	printf("%d\n", printf("%-10.5s.\n", (char *) NULL));
	printf("\n");
	ft_printf("%d\n", ft_printf("%-45.20stango\n", "alhambra"));
	printf("%d\n", printf("%-45.20stango\n", "alhambra"));
	printf("\n");
	ft_printf("%d\n", ft_printf("%30.5s!\n", "-> almeria"));
	printf("%d\n", printf("%30.5s!\n", "-> almeria"));
	printf("\n");
}

void	hex_test(void)
{
	printf("hex tests\n");
	ft_printf("%d\n", ft_printf("%30c!\n", 'X'));
	printf("%d\n", printf("%30c!\n", 'X'));
	printf("\n");
	ft_printf("%d\n", ft_printf("%-2c!\n", 'X'));
	printf("%d\n", printf("%-2c!\n", 'X'));
	printf("\n");
	ft_printf("%d\n", ft_printf("%-5p!\n", NULL));
	printf("%d\n", printf("%-5p!\n", NULL));
	printf("\n");
	ft_printf("%-5x!\n", 0);
	printf("%-5x!\n", 0);
	printf("\n");
	ft_printf("%d\n", ft_printf("%-5.3xok\n", 10));
	printf("%d\n", printf("%-5.3xok\n", 10));
	printf("\n");
	ft_printf("%d\n", ft_printf("%9.p\n", NULL));
	printf("%d\n", printf("%9.p\n", NULL));
	printf("\n");
}

int	main(void)
{
	str_test();
	hex_test();
	return (0);
}
