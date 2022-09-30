/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:39:34 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/16 19:39:51 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*routine_floor(void *arg)
{
	t_img	*img;
	t_game	*g;
	int		i;
	int		start;
	int		end;

	i = ((t_th_arg *)arg)->i;
	img = ((t_th_arg *)arg)->data[0];
	g = ((t_th_arg *)arg)->data[1];
	start = get_start(i, g->img_h / 2, g->img_h - 1, N_THREAD);
	end = get_end(i, g->img_h / 2, g->img_h - 1, N_THREAD);
	floorcasting(start, end, img, g);
	return (arg);
}

void	*routine_sky(void *arg)
{
	t_img	*img;
	t_game	*g;
	int		i;
	int		start;
	int		end;

	i = ((t_th_arg *)arg)->i;
	img = ((t_th_arg *)arg)->data[0];
	g = ((t_th_arg *)arg)->data[1];
	start = get_start(i, 0, g->img_w - 1, N_THREAD);
	end = get_end(i, 0, g->img_w - 1, N_THREAD);
	skycasting(start, end, img, g);
	return (arg);
}

void	*routine_wall(void *arg)
{
	t_img	*img;
	t_game	*g;
	int		i;
	int		start;
	int		end;

	i = ((t_th_arg *)arg)->i;
	img = ((t_th_arg *)arg)->data[0];
	g = ((t_th_arg *)arg)->data[1];
	start = get_start(i, 0, g->img_w - 1, N_THREAD);
	end = get_end(i, 0, g->img_w - 1, N_THREAD);
	raycasting(start, end, img, g);
	return (arg);
}

void	*routine_rescale(void *arg)
{
	int			i;
	int			j;
	int			end;
	t_img		*img;
	t_game		*g;

	i = get_start(((t_th_arg *)arg)->i, 0, SCREEN_H, N_THREAD);
	end = get_end(((t_th_arg *)arg)->i, 0, SCREEN_H, N_THREAD);
	img = ((t_th_arg *)arg)->data[0];
	g = ((t_th_arg *)arg)->data[1];
	while (i <= end)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			my_mlx_pixel_put(
				&g->full_buffer,
				j,
				i * (SCREEN_H - UI_H) / SCREEN_H,
				mlx_get_pixel(img, j * SCALE, i * SCALE - !!i));
			j++;
		}
		i++;
	}
	return (arg);
}
