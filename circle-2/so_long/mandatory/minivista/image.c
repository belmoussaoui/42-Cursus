/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:30:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 01:49:34 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	load_xpm_file(t_render *render, char *filepath, t_sprite *sprite)
{
	sprite->image = mlx_xpm_file_to_image(render->mlx, filepath,
			&sprite->width, &sprite->height);
	sprite->pixels = mlx_get_data_addr(sprite->image, &sprite->bits_per_pixel,
			&sprite->line_length, &sprite->endian);
}

void	create_sprite(t_render *render, t_sprite *sprite, int w, int h)
{
	sprite->image = mlx_new_image(render->mlx, w, h);
	sprite->width = w;
	sprite->height = h;
	sprite->pixels = mlx_get_data_addr(sprite->image, &sprite->bits_per_pixel,
			&sprite->line_length, &sprite->endian);
}

void	blt(t_sprite *src, t_sprite *dst, int sx, int sy, int dx, int dy)
{
	int		x;
	int		y;
	char	*pixel_dst;
	char	*pixel_src;
	int		color;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			pixel_dst = dst->pixels + ((y + dy) * dst->line_length + (x + dx)
					* (dst->bits_per_pixel / 8));
			pixel_src = src->pixels + ((y + sy) * src->line_length + (x + sx)
					* (src->bits_per_pixel / 8));
			color = (*(int *)pixel_src);
			if (color >= 0)
				*(unsigned int *) pixel_dst = *(unsigned int *) pixel_src;
			if (color > 0 && *(unsigned int *) pixel_dst == 0)
				*(unsigned int *) pixel_dst = 0xff000000;
			x++;
		}
		y++;
	}
}

void	clear_sprite(t_sprite *sprite)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < sprite->height)
	{
		x = 0;
		while (x < sprite->width)
		{
			pixel = sprite->pixels + (y * sprite->line_length + x
					* (sprite->bits_per_pixel / 8));
			*(unsigned int *) pixel = 0xff000000;
			x++;
		}
		y++;
	}
}
