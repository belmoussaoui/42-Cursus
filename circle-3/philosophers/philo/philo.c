/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:10:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/05 19:20:35 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo *philo)
{
	long	timestamp_in_ms;
	char	*action;

	pthread_mutex_lock(&philo->dinner->mutex_print);
	timestamp_in_ms = get_timestamp_in_ms(philo->dinner->start_time);
	if (philo->state == FORK)
		action = "has taken a fork";
	else if (philo->state == EAT)
		action = "is eating";
	else if (philo->state == SLEEP)
		action = "is sleeping";
	else if (philo->state == THINK)
		action = "is thinking";
	else
		action = "died";
	printf("%ld %d %s\n", timestamp_in_ms, philo->id, action);
	pthread_mutex_unlock(&philo->dinner->mutex_print);
}

void	philo_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->left_fork]);
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->right_fork]);
	philo->state = FORK;
	print_log(philo);
	print_log(philo);
	philo->state = EAT;
	print_log(philo);
	philo->time_last_meal = get_timestamp_in_ms(philo->dinner->start_time);
	usleep(philo->dinner->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->right_fork]);
	philo->state = SLEEP;
	print_log(philo);
	usleep(philo->dinner->time_to_sleep * 1000);
	philo->state = THINK;
	print_log(philo);
}

void	*philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->dinner->in_progress)
		philo_loop(philo);
	return (NULL);
}

int	play_philo(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->start_time = get_timestamp_in_ms(0);
	dinner->in_progress = 1;
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
