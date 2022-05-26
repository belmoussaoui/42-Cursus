/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:49:32 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/26 17:55:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_is_starving(t_dinner *dinner)
{
	long	timestamp_in_ms;

	if (dinner->time_to_die < get_timestamp_in_ms(dinner->start_time)
		- dinner->time_last_meal)
	{
		sem_wait(dinner->sem_print);
		timestamp_in_ms = get_timestamp_in_ms(dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, dinner->philo_id, "died");
		dinner->in_progress = 0;
		exit(1);
	}
}

void	check_is_dinner_end(t_dinner *dinner)
{
	sem_wait(dinner->sem_dead);
	sem_wait(dinner->sem_print);
	if (dinner->meal_count >= dinner->number_of_eat + 1)
	{
		dinner->in_progress = 0;
		exit(1);
	}
	sem_post(dinner->sem_print);
	sem_post(dinner->sem_dead);
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
			sem_wait(dinner->sem_dead);
			check_is_starving(dinner);
			sem_post(dinner->sem_dead);
			i++;
		}
		if (dinner->number_of_eat > 0)
		{
			check_is_dinner_end(dinner);
		}
	}
}
