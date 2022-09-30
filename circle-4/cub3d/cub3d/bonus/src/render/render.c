/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:06:51 by bel-mous          #+#    #+#             */
/*   Updated: 2022/08/16 19:44:58 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	compute_pixels(t_img *img, t_game *g, void *(*routine)(void *))
{
	pthread_t	th[N_THREAD];
	int			i;
	t_th_arg	*arg;

	i = 0;
	while (i < N_THREAD)
	{
		arg = x_malloc(sizeof(t_th_arg));
		arg->i = i;
		arg->data[0] = img;
		arg->data[1] = g;
		if (pthread_create(&th[i], NULL, routine, arg))
			exit_error("unable to create thread");
		i++;
	}
	i = 0;
	while (i < N_THREAD)
	{
		pthread_join(th[i], (void **)&arg);
		free(arg);
		i++;
	}
}

static void	put_fps(t_game *g)
{
	char	buffer[100];

	sprintf(buffer, "%d fps", g->fps);
	mlx_string_put(
		g->mlx,
		g->window,
		10,
		(TILEMAP_SIZE + 1) * g->map.height,
		0x00FFFFFF,
		buffer);
}

void	render(t_game *game)
{
	t_img	*img;

	img = &game->small_buffer;
	ft_memset(game->map.visible_tiles, 0,
		game->map.width * game->map.height * sizeof(bool));
	compute_pixels(img, game, routine_floor);
	compute_pixels(img, game, routine_sky);
	compute_pixels(img, game, routine_wall);
	render_sprites(game);
	render_gun(game);
	compute_pixels(img, game, routine_rescale);
	img = &game->full_buffer;
	render_ui(img, game);
	mlx_put_image_to_window(game->mlx, game->window, img->img, 0, 0);
	put_fps(game);
}
