/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:26:44 by bel-mous          #+#    #+#             */
/*   Updated: 2022/09/30 01:07:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_index(int code, t_game *g)
{
	if (code == K_W || code == K_UP)
		g->title.index = (g->title.index + 1) % 2;
	else if (code == K_S || code == K_DOWN)
		g->title.index = (g->title.index - 1);
	else if (code == K_ENTER || code == K_SPACE)
	{
		if (g->title.index == 0)
		{
			mlx_hook(g->window, K_PRESS_EVENT, K_PRESS_EVENT, key_down, g);
			g->scene = GAME;
		}
		else
			quit(g);
	}
	if (g->title.index < 0)
		g->title.index = 1;
	return (0);
}

void	title_start(t_game *g)
{
	g->title.index = 0;
	g->title.render = get_new_img(g->mlx, SCREEN_W, SCREEN_H);
	g->title.options = get_img_from_xpm(g->mlx, "img/title/options.xpm");
	g->title.newgame[0] = get_img_from_xpm(g->mlx, "img/title/newgame1.xpm");
	g->title.newgame[1] = get_img_from_xpm(g->mlx, "img/title/newgame2.xpm");
	g->title.select = get_img_from_xpm(g->mlx, "img/title/select1.xpm");
	g->title.quit[0] = get_img_from_xpm(g->mlx, "img/title/quit1.xpm");
	g->title.quit[1] = get_img_from_xpm(g->mlx, "img/title/quit2.xpm");
	g->title.hud = get_img_from_xpm(g->mlx, "img/hud.xpm");
	g->title.chars = get_img_from_xpm(g->mlx, "img/chars.xpm");
	g->title.faces = get_img_from_xpm(g->mlx, "img/faces.xpm");
	mlx_hook(g->window, K_PRESS_EVENT, K_PRESS_EVENT, move_index, g);
}

void	title_update(t_game *game)
{
	static int	accu;

	if (accu == 0)
		title_start(game);
	else
		title_draw(game);
	accu++;
}
