/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:49:32 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/12 13:16:29 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_starving(t_dinner *dinner, t_philo *philo)
{
	long	timestamp_in_ms;

	if (dinner->time_to_die < get_timestamp_in_ms(dinner->start_time)
		- philo->time_last_meal)
	{
		pthread_mutex_lock(&dinner->mutex_print);
		timestamp_in_ms = get_timestamp_in_ms(philo->dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, philo->id, "died");
		dinner->in_progress = 0;
		pthread_mutex_unlock(&dinner->mutex_print);
	}
}

void	check_is_dinner_end(t_dinner *dinner)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < dinner->number_of_philo)
	{
		philo = dinner->philo[i];
		if (philo.meal_count < dinner->number_of_eat)
			return ;
		i++;
	}
	pthread_mutex_lock(&dinner->mutex_print);
	dinner->in_progress = 0;
	pthread_mutex_unlock(&dinner->mutex_print);
}

void	check_dead(t_dinner *dinner)
{
	int	i;

	while (dinner->in_progress)
	{
		i = 0;
		usleep(100);
		while (dinner->in_progress && i < dinner->number_of_philo)
		{
			pthread_mutex_lock(&dinner->mutex_dead);
			check_is_starving(dinner, &dinner->philo[i]);
			pthread_mutex_unlock(&dinner->mutex_dead);
			i++;
		}
		if (dinner->number_of_eat > 0)
		{
			pthread_mutex_lock(&dinner->mutex_dead);
			check_is_dinner_end(dinner);
			pthread_mutex_unlock(&dinner->mutex_dead);
		}
	}
}
