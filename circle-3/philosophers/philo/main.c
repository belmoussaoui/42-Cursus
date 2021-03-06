/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:49:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/05/12 13:32:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (!setup(argc, argv, &dinner))
		return (1);
	play_philo(&dinner);
	clear_dinner(&dinner);
	return (0);
}
