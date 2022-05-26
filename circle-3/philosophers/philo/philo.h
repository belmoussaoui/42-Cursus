/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:55:25 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/26 19:11:09 by bel-mous         ###   ########.fr       */
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

struct	s_dinner;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				left_fork;
	int				right_fork;
	int				meal_count;
	long			time_last_meal;
	struct s_dinner	*dinner;
}	t_philo;

typedef struct s_dinner
{
	t_philo			*philo;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	long			start_time;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_dead;
	int				in_progress;
}	t_dinner;

int		check_arg(char *arg);

int		exit_with_message(char *message);
int		setup(int argc, char **argv, t_dinner *dinner);

int		play_philo(t_dinner *dinner);

long	get_timestamp_in_ms(long start_time);
void	ft_sleep(unsigned long duration, t_dinner *dinner);

void	print_log(t_philo *philo, char *message);
void	check_dead(t_dinner *dinner);

void	clear_dinner(t_dinner *dinner);

#endif