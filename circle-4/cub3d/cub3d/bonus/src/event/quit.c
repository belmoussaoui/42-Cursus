/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:51:06 by vrogiste          #+#    #+#             */
/*   Updated: 2022/09/30 01:43:10 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_images(t_list lst, t_game *g)
{
	size_t		i;
	t_node		*node;
	t_img		*texture;

	i = 0;
	node = lst.head;
	while (i < clst_size(lst))
	{
		texture = node->content;
		if (texture)
			mlx_destroy_image(g->mlx, texture->img);
		node = node->next;
		i++;
	}
}

static void	free_sprites(t_game *g)
{
	int	i;

	i = 0;
	while (i < SPRITE_MAX)
	{
		if (g->list_sprite[i])
			mlx_destroy_image(g->mlx, g->list_sprite[i]->t.img);
		free(g->list_sprite[i]);
		i++;
	}
	i = 0;
	while (i < GUN_MAX)
	{
		if (g->list_gun[i])
			mlx_destroy_image(g->mlx, g->list_gun[i]->s.t.img);
		free(g->list_gun[i]);
		i++;
	}
}

static void	destroy_hud(t_game *g)
{
	mlx_destroy_image(g->mlx, g->title.options.img);
	mlx_destroy_image(g->mlx, g->title.newgame[0].img);
	mlx_destroy_image(g->mlx, g->title.newgame[1].img);
	mlx_destroy_image(g->mlx, g->title.quit[0].img);
	mlx_destroy_image(g->mlx, g->title.quit[1].img);
	mlx_destroy_image(g->mlx, g->title.select.img);
	mlx_destroy_image(g->mlx, g->title.render.img);
	mlx_destroy_image(g->mlx, g->title.hud.img);
	mlx_destroy_image(g->mlx, g->title.chars.img);
	mlx_destroy_image(g->mlx, g->title.faces.img);
}

int	quit(t_game *g)
{
	int	i;

	i = 0;
	while (i < WALL_MAX)
	{
		clear_images(g->walls[i].imgs, g);
		i++;
	}
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_image(g->mlx, g->sky.img);
	mlx_destroy_image(g->mlx, g->floor.img);
	mlx_destroy_image(g->mlx, g->small_buffer.img);
	mlx_destroy_image(g->mlx, g->full_buffer.img);
	destroy_hud(g);
	free(g->map.data);
	free(g->map.object_map);
	free(g->map.visible_tiles);
	free_sprites(g);
	lst_clear(&g->doors, free);
	exit(EXIT_SUCCESS);
	return (0);
}
