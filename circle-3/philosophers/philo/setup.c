/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:43:36 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/03 17:56:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_args(int argc, t_game *game)
{
	if (game->number_of_philo < 2 || game->number_of_philo > 200)
		return (exit_with_message("number of philosophers is invalid"));
	if (game->time_to_die < 60 || game->time_to_eat < 60
		|| game->time_to_sleep < 60)
		return (exit_with_message("time argument is invalid"));
	if (argc == 6 && game->number_of_eat <= 0)
		return (exit_with_message("number of eat is invalid"));
	return (1);
}

int	setup_args(int argc, char **argv, t_game *game)
{
	if (argc != 5 && argc != 6)
		return (exit_with_message("the number of arguments is invalid"));
	game->number_of_philo = check_arg(argv[1]);
	game->time_to_die = check_arg(argv[2]);
	game->time_to_eat = check_arg(argv[3]);
	game->time_to_sleep = check_arg(argv[4]);
	if (argc == 6)
		game->number_of_eat = check_arg(argv[5]);
	return (is_valid_args(argc, game));
}

int	setup_philo(t_game *game)
{
	int	i;

	game->philo = malloc(sizeof(game->philo) * game->number_of_philo);
	if (!game->philo)
		return (0);
	i = 0;
	while (i < game->number_of_philo)
	{
		game->philo[i].id = i + 1;
		game->philo[i].left_fork = i % game->number_of_philo;
		game->philo[i].right_fork = (i + 1) % game->number_of_philo;
		game->philo[i].meal_count = 0;
		game->philo[i].game = game;
		i++;
	}
	return (1);
}

int	setup(int argc, char **argv, t_game *game)
{
	if (!setup_args(argc, argv, game))
		return (0);
	if (!setup_philo(game))
		return (0);
	return (1);
}
