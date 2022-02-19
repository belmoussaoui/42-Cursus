/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:04 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/19 16:06:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *, ... );

int main ()
{
	int i = -1245;
	ft_printf("%d\n", ft_printf("hello world! %d %x %s\n", i, i, "test ok"));
	printf("%d\n", printf("hello world! %d %x %s\n", i, i, "test ok"));

	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}
