/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:56:08 by jmorel            #+#    #+#             */
/*   Updated: 2021/11/13 15:03:37 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int i, int j, int x, int y)
{
	if (i == 0 && j == 0)
		ft_putchar('/');
	else if (i == x - 1 && j == 0)
		ft_putchar('\\');
	else if (i == 0 && j == y - 1)
		ft_putchar('\\');
	else if (i == x - 1 && j == y - 1)
		ft_putchar('/');
	else if (j == 0 || i == 0)
		ft_putchar('*');
	else if (j == y - 1 || i == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	char	i;
	char	j;

	i = 0;
	j = 0;
	while (i < x)
	{
		while (j < y)
		{
			print_char(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}
