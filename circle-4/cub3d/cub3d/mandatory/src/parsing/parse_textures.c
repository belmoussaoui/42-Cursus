/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:04:36 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/15 13:58:21 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_color(char *line)
{
	int		color;
	int		i;
	char	**arr;
	uint8_t	n;

	arr = ft_split(line, ',');
	if (str_arr_len(arr) != 3)
		exit_error("invalid color arguments");
	i = 0;
	color = 0;
	while (arr[i])
	{
		color <<= 8;
		if (atoui8_error(arr[i], &n))
			exit_error("invalid color value");
		color += n;
		i++;
	}
	str_arr_free(arr);
	return (color);
}

static bool	is_full(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!game->textures[i].img)
			return (false);
		i++;
	}
	return (game->map.floor > -1 && game->map.ceil > -1);
}

void	parse_textures(t_game *game, int fd)
{
	char	*line;

	while (!is_full(game))
	{
		line = get_next_non_empty_line(fd);
		line[strlen(line) - 2] = '\0';
		if (is_token(line, "NO :SO :EA :WE ", ':', 3))
			game->textures[get_direction(line[0])] = get_img_from_xpm(
					game->mlx,
					skip_spaces(line + 2));
		else if (!str_n_cmp("F ", line, 2))
			game->map.floor = parse_color(skip_spaces(line + 1));
		else if (!str_n_cmp("C ", line, 2))
			game->map.ceil = parse_color(skip_spaces(line + 1));
		else
			exit_error("invalid identifier");
		free(line);
	}
}
