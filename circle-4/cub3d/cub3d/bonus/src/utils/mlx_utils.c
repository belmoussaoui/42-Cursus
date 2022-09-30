/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:22:47 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/16 18:20:12 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

t_img	get_new_img(void *mlx, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(
			img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_img	get_img_from_xpm(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(
			mlx,
			path,
			&img.width,
			&img.height);
	if (!img.img)
		exit_error("unable to load image");
	img.addr = mlx_get_data_addr(
			img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	return (img);
}
