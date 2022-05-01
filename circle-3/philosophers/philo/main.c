/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:49:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/01 15:42:08 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup(int argc, char **argv, t_args *args)
{
	if (argc != 5 && argc != 6)
		return (exit_with_message("the number of arguments is invalid", 0));
	args->number_of_philo = check_arg(argv[1]);
	args->time_to_die = check_arg(argv[2]);
	args->time_to_eat = check_arg(argv[3]);
	args->time_to_sleep = check_arg(argv[4]);
	if (argc == 6)
		args->number_of_eat = check_arg(argv[5]);
	if (args->number_of_philo == -1 || args->time_to_die == -1
		|| args->time_to_eat == -1 || args->time_to_sleep == -1
		|| (argc == 6 && args->number_of_eat == -1))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (!setup(argc, argv, &args))
		return (1);
	print_args(&args);
	return (0);
}
