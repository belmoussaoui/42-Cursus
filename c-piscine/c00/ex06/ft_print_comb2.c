/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:37:25 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/11 12:57:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_res(int a1, int a2, int b1, int b2)
{
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
	if (a1 != '9' || a2 != '8' || b1 != '9' || b2 != '9')
		write(1, ", ", 2);
}

void	ft_next_digit2(int *a, int *b)
{
	if (*b == '9')
	{
		(*a)++;
		*b = '0';
	}
	else
		(*b)++;
}

void	ft_print_comb2(void)
{
	int	a1;
	int	a2;
	int	b1;
	int	b2;

	a1 = '0';
	a2 = '0';
	b1 = '0';
	b2 = '0';
	while (a1 <= '9' && a2 <= '9')
	{
		while (b1 <= '9' && b2 <= '9')
		{
			ft_print_res(a1, a2, b1, b2);
			ft_next_digit2(&b1, &b2);
		}
		ft_next_digit2(&a1, &a2);
		b1 = a1;
		b2 = a2;
		ft_next_digit2(&b1, &b2);
	}
}
