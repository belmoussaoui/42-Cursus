/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:49:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/23 19:26:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void exit_with_message(char *message, int status)
{
	printf("%s\n", message);
	exit(status);
}

void setup(int argc, char **argv, t_args *args)
{
	if (argc != 5 && argc != 6)
		exit_with_message("the number of arguments is invalid", EXIT_SUCCESS);
	args->number_of_philosophers = check_arg(argv[1]);
	args->time_to_die = check_arg(argv[2]);
	args->time_to_eat = check_arg(argv[3]);
	args->time_to_sleep = check_arg(argv[4]);
	if (argc == 6)
		args->number_of_eat = check_arg(argv[5]);
}

int	main(int argc, char **argv)
{
	t_args	args;
	setup(argc, argv, &args);
	return (0);
}