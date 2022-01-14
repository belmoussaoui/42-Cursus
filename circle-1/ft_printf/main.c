/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:52:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/14 18:11:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "stdio.h"


int ft_printf(const char * format, ...);
void ft_puthex_fd(int n, int fd);


int	main()
{
	void *ptr;
	int t = 100;
	
	ptr = &t;
	ft_printf("hello world %% d %X %d %s %c %u %p\n", 12541, 54142, "oktest", 'o', -10, ptr);
	printf(   "hello world %% d %X %d %s %c %u %p\n", 12541, 54142, "oktest", 'o', -10, ptr);

	int x = 10;
	ft_puthex_fd(111, 1);
	printf ("%x\n", x);
}