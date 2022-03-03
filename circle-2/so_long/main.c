/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:12:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/03 19:34:25 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;


void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		img_width = 32;
	int		img_height = 32;
	t_image	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");

	//img.img = mlx_new_image(mlx, 800, 600);
	img.img = mlx_xpm_file_to_image(mlx, "icon.xpm", &img_width, &img_height);
	if (!img.img)
		return (0);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// int i = 0;
	// while (i++ < 800)
	// 	my_mlx_pixel_put(&img, i-1, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	
	mlx_loop(mlx);
}