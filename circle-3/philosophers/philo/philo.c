/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:10:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/05 16:47:10 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo *philo)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&philo->dinner->mutex_print);
	timestamp_in_ms = get_timestamp_in_ms(philo->dinner->start_time);
	if (philo->state == FORK)
		printf("%ld %d %s", timestamp_in_ms, philo->id, "has taken a fork\n");
	else if (philo->state == EAT)
		printf("%ld %d %s", timestamp_in_ms, philo->id, "is eating\n");
	else if (philo->state == SLEEP)
		printf("%ld %d %s", timestamp_in_ms, philo->id, "is sleeping\n");
	else if (philo->state == THINK)
		printf("%ld %d %s", timestamp_in_ms, philo->id, "is thinking\n");
	else
		printf("%ld %d %s", timestamp_in_ms, philo->id, "died\n");
	pthread_mutex_unlock(&philo->dinner->mutex_print);
}

void	*philo_life(t_philo *philo)
{
	philo->state = FORK;
	print_log(philo);
	return (NULL);
}

int	play_philo(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->start_time = get_timestamp_in_ms(0);
	while (i < dinner->number_of_philo)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL, (void *)philo_life,
				&dinner->philo[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < dinner->number_of_philo)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
	return (1);
}
