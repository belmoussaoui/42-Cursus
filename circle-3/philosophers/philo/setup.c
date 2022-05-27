/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:43:36 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/27 18:48:13 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_args(int argc, t_dinner *dinner)
{
	if (dinner->number_of_philo < 1 || dinner->number_of_philo > 200)
		return (exit_with_message("number of philosophers is invalid"));
	if (dinner->time_to_die < 60 || dinner->time_to_eat < 60
		|| dinner->time_to_sleep < 60)
		return (exit_with_message("time argument is invalid"));
	if (argc == 6 && dinner->number_of_eat <= 0)
		return (exit_with_message("number of eat is invalid"));
	return (1);
}

int	setup_args(int argc, char **argv, t_dinner *dinner)
{
	if (argc != 5 && argc != 6)
		return (exit_with_message("the number of arguments is invalid"));
	dinner->number_of_philo = check_arg(argv[1]);
	dinner->time_to_die = check_arg(argv[2]);
	dinner->time_to_eat = check_arg(argv[3]);
	dinner->time_to_sleep = check_arg(argv[4]);
	if (argc == 6)
		dinner->number_of_eat = check_arg(argv[5]);
	else
		dinner->number_of_eat = 0;
	return (is_valid_args(argc, dinner));
}

int	setup_philo(t_dinner *dinner)
{
	int	i;

	dinner->philo = malloc(sizeof(t_philo) * dinner->number_of_philo);
	if (!dinner->philo)
		return (0);
	i = 0;
	while (i < dinner->number_of_philo)
	{
		dinner->philo[i].id = i + 1;
		dinner->philo[i].left_fork = i;
		dinner->philo[i].right_fork = (i + 1) % dinner->number_of_philo;
		dinner->philo[i].meal_count = 0;
		dinner->philo[i].dinner = dinner;
		i++;
	}
	return (1);
}

int	setup_mutexes(t_dinner *dinner)
{
	int	i;

	if (pthread_mutex_init(&dinner->mutex_print, NULL) != 0)
		return (0);
	dinner->mutex_forks = malloc(sizeof(pthread_mutex_t)
			* dinner->number_of_philo);
	if (!dinner->mutex_forks)
		return (0);
	i = 0;
	while (i < dinner->number_of_philo)
	{
		if (pthread_mutex_init(&dinner->mutex_forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&dinner->mutex_dead, NULL) != 0)
		return (0);
	return (1);
}

int	setup(int argc, char **argv, t_dinner *dinner)
{
	if (!setup_args(argc, argv, dinner))
		return (0);
	if (!setup_philo(dinner))
		return (0);
	if (!setup_mutexes(dinner))
		return (0);
	return (1);
}
