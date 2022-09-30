/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:04:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/09/28 22:17:26 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_image_center(t_game *g, t_img img, int offset_x, int offset_y)
{
	int	cx;
	int	cy;

	cx = SCREEN_W / 2 + offset_x;
	cy = SCREEN_H / 2 + offset_y;
	mlx_put_image_to_window(g->mlx, g->window, img.img, cx - img.width / 2, cy);
}

static void	draw_background(t_game *game)
{
	int		i;
	int		j;
	t_img	render;

	render = game->title.render;
	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			if ((i >= SCREEN_H / 2 - 300 + 20 && i <= SCREEN_H / 2 - 300 + 63)
				|| i == SCREEN_H / 2 - 300 + 66 || i == SCREEN_H / 2 - 300 + 67)
				my_mlx_pixel_put(&render, j, i, 0x000000);
			else if ((i >= SCREEN_H / 2 - 190 && i <= SCREEN_H / 2 + 190)
				&& j > SCREEN_W / 2 - 300 && j < SCREEN_W / 2 + 300)
				my_mlx_pixel_put(&render, j, i, BACKGROUND1);
			else
				my_mlx_pixel_put(&render, j, i, BACKGROUND2);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->window, render.img, 0, 0);
}

static void	draw_commands(t_game *g)
{
	int	cx;
	int	cy;

	cx = SCREEN_W / 2;
	cy = SCREEN_H / 2;
	mlx_put_image_to_window(g->mlx, g->window, g->title.options.img,
		cx - g->title.options.width / 2, cy - 300);
	if (g->title.index == 0)
		put_image_center(g, g->title.newgame[1], -30, -190);
	else
		put_image_center(g, g->title.newgame[0], -30, -190);
	if (g->title.index != 1)
		put_image_center(g, g->title.quit[0], -30, -140);
	else
		put_image_center(g, g->title.quit[1], -30, -140);
}

static void	draw_select(t_game *g)
{
	put_image_center(g, g->title.select, -250, -190 + g->title.index * 50);
}

void	title_draw(t_game *game)
{
	draw_background(game);
	draw_commands(game);
	draw_select(game);
}
