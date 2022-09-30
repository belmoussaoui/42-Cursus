/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:04:36 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/17 18:50:06 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_img(t_texture *texture, t_img img)
{
	t_node	*node;

	node = new_node(x_calloc(1, sizeof(t_img)));
	*(t_img *)node->content = img;
	clst_add_back(&texture->imgs, node);
	if (!texture->img)
		texture->img = node->content;
}

static void	add_wall(char *str, t_game *g)
{
	int			i;
	char		**arr;

	arr = ft_split(str, ',');
	i = 0;
	while (arr[i])
	{
		add_img(
			&g->walls[str[0] - 49],
			get_img_from_xpm(g->mlx, skip_spaces(arr[i] + 2)));
		i++;
	}
	str_arr_free(arr);
}

static void	parse_ceiling(t_game *g, t_dy_str *s)
{
	char		**spt;

	spt = ft_split(s->str, ' ');
	g->sky = get_img_from_xpm(g->mlx, spt[1]);
	if (spt[2])
		g->map.ceil_repeat = ft_atoi(spt[2]);
	else
		g->map.ceil_repeat = 1;
	g->map.ceil = 1;
	str_arr_free(spt);
}

void	parse_textures(t_game *g, int fd)
{
	char		*line;
	t_dy_str	s;

	while (g->map.ceil == -1)
	{
		s = dy_str_new();
		line = get_next_non_empty_line(fd);
		dy_str_append_str(&s, line);
		free(line);
		while (ft_strchr(" \t\n\r", s.str[s.len - 1]))
			dy_str_pop_back(&s);
		if (isascii_48(s.str[0]) && s.str[0] != 'F' && s.str[0] != 'C')
			add_wall(s.str, g);
		else if (!str_n_cmp("F ", s.str, 2))
			g->floor = get_img_from_xpm(g->mlx, skip_spaces(s.str + 2));
		else if (!str_n_cmp("C ", s.str, 2))
			parse_ceiling(g, &s);
		else
			exit_error("invalid identifier");
		dy_str_destroy(&s);
	}
}
