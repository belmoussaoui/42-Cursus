/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:55:25 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/11 17:58:41 by bel-mous         ###   ########.fr       */
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
	int				time_last_meal;
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

void	print_dinner(t_dinner *dinner);
void	print_philo(t_philo *philo);

int		exit_with_message(char *message);
int		setup(int argc, char **argv, t_dinner *dinner);

int		play_philo(t_dinner *dinner);

int		get_timestamp_in_ms(long start_time);
void	ft_sleep(unsigned long duration);

void	print_log(t_philo *philo, char *message);
void	check_dead(t_dinner *dinner);

#endif