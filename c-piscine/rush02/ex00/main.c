/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:39:36 by llaruell          #+#    #+#             */
/*   Updated: 2021/11/28 21:16:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int main(int argc, char **argv)
{
	t_data data;
	// Un seul parametre
	if (argc < 2 || argc > 3)
		return (0); // A modifier
	if (!ft_is_valid_args(argc, argv))
		return (0);
	ft_init(&data, argv);
	return (0);
}
