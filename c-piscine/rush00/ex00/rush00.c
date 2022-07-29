/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:16:27 by jmorel            #+#    #+#             */
/*   Updated: 2021/11/13 12:27:24 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('o');
	else if (i == x - 1 && j == y - 1)
		ft_putchar('o');
	else if (j == 0 && i == x - 1)
		ft_putchar('o');
	else if (i == 0 && j == y - 1)
		ft_putchar('o');
	else if (i == 0 || i == x - 1)
		ft_putchar('|');
	else
		ft_putchar('-');
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
				print_char();
			else
				ft_putchar(' ');
			i++;
		}
		i = 0;
		ft_putchar('\n');
		j++;
	}
}
