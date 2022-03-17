/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:30:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/17 18:50:12 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	load_texture(t_render *render, char *filepath, t_sprite *sprite)
{
	sprite->image.texture = mlx_xpm_file_to_image(render->mlx, filepath, &sprite->width, &sprite->height);
	sprite->image.pixels = mlx_get_data_addr(sprite->image.texture, &sprite->image.bits_per_pixel, &sprite->image.line_length, &sprite->image.endian);
}

void	create_sprite(t_render *render, t_sprite *sprite, int w, int h)
{
	sprite->width = w;
	sprite->height = h;
	create_image(render, &sprite->image, w, h);
}

void	create_image(t_render *render, t_image *image, int w, int h)
{
	image->texture = mlx_new_image(render->mlx, w, h);
	image->pixels = mlx_get_data_addr(image->texture, &image->bits_per_pixel, &image->line_length, &image->endian);
}

void	draw_sprite(t_image *src, t_image *dst, int sx, int sy)
{
	int		x;
	int		y;
	char	*pixel_dst;
	char	*pixel_src;

	y = 0;
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			pixel_dst = dst->pixels + (y * dst->line_length + x * (dst->bits_per_pixel / 8));
			pixel_src = src->pixels + ((y + sy) * src->line_length + (x + sx) * (src->bits_per_pixel / 8));
			*(unsigned int *) pixel_dst = *(unsigned int *) pixel_src;
			x++;
		}
		y++;
	}
}
