/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:16:27 by jmorel            #+#    #+#             */
/*   Updated: 2021/11/13 13:19:17 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('A');
	else if (j == 0 && i == x - 1)
		ft_putchar('A');
	else if (i == 0 && j == y - 1)
		ft_putchar('C');
	else if (i == x - 1 && j == y - 1)
		ft_putchar('C');
	else if (i == 0 || i == x - 1)
		ft_putchar('B');
	else
		ft_putchar('B');
}

void	rush(int x,	int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				print_char(i, j, x, y);
			else
				ft_putchar(' ');
			i++;
		}
		i = 0;
		ft_putchar('\n');
		j++;
	}
}
