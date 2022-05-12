/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:10:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/12 14:19:21 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo *philo, char *message)
{
	long	timestamp_in_ms;

	pthread_mutex_lock(&philo->dinner->mutex_print);
	if (philo->dinner->in_progress)
	{
		timestamp_in_ms = get_timestamp_in_ms(philo->dinner->start_time);
		printf("%ld %d %s\n", timestamp_in_ms, philo->id, message);
	}
	pthread_mutex_unlock(&philo->dinner->mutex_print);
}

void	philo_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->left_fork]);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->right_fork]);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(&philo->dinner->mutex_dead);
	print_log(philo, "is eating");
	philo->time_last_meal = get_timestamp_in_ms(philo->dinner->start_time);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->dinner->mutex_dead);
	ft_sleep(philo->dinner->time_to_eat, philo->dinner);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->right_fork]);
	print_log(philo, "is sleeping");
	ft_sleep(philo->dinner->time_to_sleep, philo->dinner);
	print_log(philo, "is thinking");
}

void	*philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(50, philo->dinner);
	while (42)
	{
		pthread_mutex_lock(&philo->dinner->mutex_print);
		if (!philo->dinner->in_progress)
			break ;
		pthread_mutex_unlock(&philo->dinner->mutex_print);
		if (philo->dinner->number_of_philo > 1)
			philo_loop(philo);
	}
	pthread_mutex_unlock(&philo->dinner->mutex_print);
	return (NULL);
}

int	play_philo(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->in_progress = 1;
	dinner->start_time = get_timestamp_in_ms(0);
	while (i < dinner->number_of_philo)
	{
		if (pthread_create(&dinner->philo[i].thread, NULL, (void *)philo_life,
				&dinner->philo[i]))
			return (0);
		i++;
	}
	check_dead(dinner);
	i = 0;
	while (i < dinner->number_of_philo)
	{
		pthread_join(dinner->philo[i].thread, NULL);
		i++;
	}
	return (1);
}
