/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:52:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 06:54:49 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	void *ptr;
	int t = 100;
	char *test;
	
	ptr = &t;
	printf("%d\n", ft_printf(" %#x \n", LONG_MIN));
	printf("%d\n", printf(" %#x \n", LONG_MIN));
	
	//printf("%10d.\n", t);
}