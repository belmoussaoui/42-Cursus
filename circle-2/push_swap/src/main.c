/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:03:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/25 21:14:08 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	play(t_game *game)
{
	if (game->n <= 5)
		lock_sort(game);
	else
		lock_sort(game);
}

int	main(int argc, char **argv)
{
    t_game game;
    game = setup_game(argc, argv);
    play(&game);
    return (0);
}                