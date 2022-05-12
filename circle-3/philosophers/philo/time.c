/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:36:42 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/12 14:21:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp_in_ms(long start_time)
{
	struct timeval	time;
	int				timestamp_in_ms;

	gettimeofday(&time, NULL);
	timestamp_in_ms = (time.tv_sec * 1000) + (time.tv_usec) / 1000 - start_time;
	return (timestamp_in_ms);
}

void	ft_sleep(unsigned long duration, t_dinner *dinner)
{
	unsigned long	start;

	start = get_timestamp_in_ms(0);
	while (42)
	{
		if (get_timestamp_in_ms(0) - start >= duration)
			break ;
		pthread_mutex_lock(&dinner->mutex_print);
		if (!dinner->in_progress)
		{
			pthread_mutex_unlock(&dinner->mutex_print);
			break ;
		}
		pthread_mutex_unlock(&dinner->mutex_print);
		usleep(100);
	}
}
