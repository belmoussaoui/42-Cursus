/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:55:25 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/01 15:42:33 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_args
{
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_eat;
}	t_args;

int		check_arg(char *arg);
void	print_args(t_args *args);
int		exit_with_message(char *message, int status);

#endif