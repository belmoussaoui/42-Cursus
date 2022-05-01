/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:49:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/01 19:46:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!setup(argc, argv, &game))
		return (1);
	print_args(&game);
	print_philo(game.philo, game.number_of_philo);
	return (0);
}
