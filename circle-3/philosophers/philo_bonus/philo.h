/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:55:25 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/26 19:58:41 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <stdatomic.h>

typedef struct s_dinner
{
	pthread_t		thread;
	int				philo_id;
	atomic_int		meal_count;
	atomic_long		time_last_meal;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	atomic_int		number_of_eat;
	long			start_time;
	sem_t			*sem_print;
	sem_t			*sem_forks;
	sem_t			*sem_dead;
	atomic_int		in_progress;
}	t_dinner;

int		check_arg(char *arg);

int		exit_with_message(char *message);
int		setup(int argc, char **argv, t_dinner *dinner);

int		play_philo(t_dinner *dinner);

long	get_timestamp_in_ms(long start_time);
void	ft_sleep(unsigned long duration, t_dinner *dinner);

void	print_log(t_dinner *dinner, char *message);
void	check_dead(t_dinner *dinner);

void	clear_dinner(t_dinner *dinner);

#endif