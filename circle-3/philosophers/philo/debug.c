/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/01 19:46:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_args(t_game *game)
{
	printf("number_of_philo = %d\n", game->number_of_philo);
	printf("time_to_die = %d\n", game->time_to_die);
	printf("time_to_eat = %d\n", game->time_to_eat);
	printf("time_to_sleep = %d\n", game->time_to_sleep);
	printf("number_of_eat = %d\n", game->number_of_eat);
}

void	print_philo(t_philo *philo, int number_of_philo)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < number_of_philo)
	{
		printf("philo_id = %d\n", philo[i].id);
		printf("left_fork = %d\n", philo[i].left_fork);
		printf("right_fork = %d\n", philo[i].right_fork);
		printf("\n");
		i++;
	}
}
