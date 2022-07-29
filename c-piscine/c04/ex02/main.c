/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:49:30 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/22 11:57:30 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_putnbr(int nb);

int main()
{
	ft_putnbr(-9209302);
	printf("\n");

	ft_putnbr(4001);
	printf("\n");

	ft_putnbr(101000);
	printf("\n");

    ft_putnbr(-1020);
	printf("\n");

    ft_putnbr(-0);
	printf("\n");

    ft_putnbr(-1);
	printf("\n");

    ft_putnbr(42);
	printf("\n");

	ft_putnbr(-2147483648);
	printf("\n");

	ft_putnbr(2147483647);
	printf("\n");

	return 0;
}
