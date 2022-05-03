/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:10:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/03 19:13:20 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(t_philo *philo)
{
	print_philo(philo);
	return (NULL);
}

int	play_philo(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->number_of_philo)
	{
		if (pthread_create(&game->philo[i].thread, NULL, (void *)philo_life,
				&game->philo[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->number_of_philo)
	{
		pthread_join(game->philo[i].thread, NULL);
		i++;
	}
	return (1);
}
