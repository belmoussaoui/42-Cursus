/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:12:11 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/24 13:53:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	if (s1[0] == '\0')
		return (-1);
	if (s2[0] == '\0')
		return (1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

// https://stackoverflow.com/a/54534556/17355718
void	ft_char_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_sort_char_tab(char **tab, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_char_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	ft_sort_char_tab(argv, argc - 1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
