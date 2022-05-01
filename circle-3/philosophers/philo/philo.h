/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:55:25 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/01 19:50:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct s_philo
{
	int	id;
	int	left_fork;
	int	right_fork;
	int	meal_count;
}	t_philo;

typedef struct s_game
{
	t_philo	*philo;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_eat;
}	t_game;

int		check_arg(char *arg);

void	print_args(t_game *game);
void	print_philo(t_philo *philo, int number_of_philo);

int		exit_with_message(char *message);
int		setup(int argc, char **argv, t_game *game);

#endif