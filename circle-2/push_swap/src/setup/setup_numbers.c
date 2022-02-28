/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:59:10 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/28 20:03:58 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**handle_one_arg(char *arg, t_game *game)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		exit(1);
	if (!args[0])
	{
		free(args);
		exit_error(game);
	}
	return (args);
}

char	**handle_many_args(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * (argc + 1));
	if (!args)
		exit(1);
	while (i < argc)
	{
		args[i] = ft_strdup(argv[i]);
		if (!args[i])
		{
			while (i > 0)
			{
				i--;
				free(args[i]);
			}
			free(args);
			exit(1);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}

void	free_argv(t_game *game, char **argv, int exit)
{
	int	i;

	i = 0;
	while (i < game->n)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	if (exit)
		exit_error(game);
}

int	check_number(char *nbr, t_game *game, char **argv)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	if (!nbr[i])
		free_argv(game, argv, 1);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			free_argv(game, argv, 1);
		res = res * 10 + nbr[i] - '0';
		i++;
		if (res > INT_MAX && !(res == (long)INT_MAX + 1 && sign == -1))
			free_argv(game, argv, 1);
	}
	return (res * sign);
}

void	check_duplicates(t_game *game, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->n)
	{
		j = i + 1;
		while (j < game->n)
		{
			if (game->numbers[i] == game->numbers[j])
				free_argv(game, argv, 1);
			j++;
		}
		i++;
	}
}
