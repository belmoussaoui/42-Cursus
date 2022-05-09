/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:10:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/09 18:48:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(t_philo *philo)
{
	long	timestamp_in_ms;
	char	*action;

	if (!philo->dinner->in_progress)
		return ;
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
	philo->state = FORK;
	print_log(philo);
	pthread_mutex_lock(&philo->dinner->mutex_forks[philo->right_fork]);
	print_log(philo);
	pthread_mutex_lock(&philo->dinner->mutex_dead);
	philo->state = EAT;
	print_log(philo);
	philo->time_last_meal = get_timestamp_in_ms(philo->dinner->start_time);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->dinner->mutex_dead);
	ft_sleep(philo->dinner->time_to_eat);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->dinner->mutex_forks[philo->right_fork]);
	philo->state = SLEEP;
	print_log(philo);
	ft_sleep(philo->dinner->time_to_sleep);
	philo->state = THINK;
	print_log(philo);
}

void	*philo_life(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(100);
	while (philo->dinner->in_progress)
		philo_loop(philo);
	return (NULL);
}

void	check_dead(t_dinner *dinner)
{
	int	i;

	while (dinner->in_progress)
	{
		i = 0;
		while (i < dinner->number_of_philo)
		{
			pthread_mutex_lock(&dinner->mutex_dead);
			if (dinner->time_to_die < get_timestamp_in_ms(dinner->start_time)
				- dinner->philo[i].time_last_meal)
			{
				dinner->philo[i].state = DEAD;
				print_log(dinner->philo);
				dinner->in_progress = 0;
				i = dinner->number_of_philo;
			}
			else if (dinner->number_of_eat && dinner->philo[i].meal_count
				>= dinner->number_of_eat)
			{
				dinner->in_progress = 0;
				i = dinner->number_of_philo;
			}
			i++;
			pthread_mutex_unlock(&dinner->mutex_dead);
		}
		usleep(1000);
	}
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
