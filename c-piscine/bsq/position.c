/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:57:49 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/29 13:26:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "position.h"

int	top_tile(int tile_id, int column)
{
	int	new_tile_id;

	new_tile_id = tile_id - column;
	if (new_tile_id < 0)
		return (-1);
	return (new_tile_id);
}

int	left_tile(int tile_id, int column)
{
	int	new_tile_id;

	new_tile_id = tile_id - 1;
	if (tile_id % column == 0)
		return (-1);
	return (new_tile_id);
}

int	top_left_tile(int tile_id, int column)
{
	int	new_tile_id;

	new_tile_id = left_tile(tile_id, column);
	new_tile_id = top_tile(new_tile_id, column);
	if (tile_id < 0)
		return (-1);
	return (new_tile_id);
}
