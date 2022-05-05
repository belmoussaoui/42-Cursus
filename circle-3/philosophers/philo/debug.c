/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:26:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/05 17:51:16 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_dinner(t_dinner *dinner)
{
	printf("number_of_philo = %d\n", dinner->number_of_philo);
	printf("time_to_die = %d\n", dinner->time_to_die);
	printf("time_to_eat = %d\n", dinner->time_to_eat);
	printf("time_to_sleep = %d\n", dinner->time_to_sleep);
	printf("number_of_eat = %d\n", dinner->number_of_eat);
	printf("start_time = %ld\n", dinner->start_time);
}

void	print_philo(t_philo *philo)
{
	int	i;

	i = 0;
	printf("\n");
	printf("philo_id = %d\n", philo[i].id);
	printf("left_fork = %d\n", philo[i].left_fork);
	printf("right_fork = %d\n", philo[i].right_fork);
	printf("\n");
	i++;
}
