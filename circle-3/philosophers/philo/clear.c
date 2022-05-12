/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:20:55 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/12 13:30:16 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_dinner(t_dinner *dinner)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&dinner->mutex_print);
	pthread_mutex_destroy(&dinner->mutex_dead);
	while (i < dinner->number_of_philo)
	{
		pthread_mutex_destroy(dinner->mutex_forks + i);
		i++;
	}
	free(dinner->philo);
	free(dinner->mutex_forks);
}
