/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:47:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/15 13:58:34 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

# define SPACES " \t"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	int		*data;
	int		width;
	int		height;
	int		ceil;
	int		floor;
}	t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_state
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	r_left;
	bool	r_right;
}	t_state;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_map		map;
	t_player	player;
	t_state		state;
	t_img		textures[4];
}	t_game;

/* check_map */
void		check_map(t_game *g);

/* get_map_str */
char		*get_map_str(int fd);

/* parse_map */
void		parse_map(char *map_str, t_game *g);

/* parse_textures */
void		parse_textures(t_game *game, int fd);

/* parse */
enum e_side	get_direction(char c);
void		parse(int argc, char **argv, t_game *game);

#endif
