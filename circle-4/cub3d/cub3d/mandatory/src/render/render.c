/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:06:51 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/20 00:09:01 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render(t_game *game)
{
	raycasting(0, &game->img, game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
}
